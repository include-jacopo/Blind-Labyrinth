/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "RIT.h"
#include "../led/led.h"
#include "../timer/timer.h"
#include "../labyrinth/labyrinth.h"

/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

//volatile int down=0;

void RIT_IRQHandler (void)
{					
	static int count=0;
	static int mode=0;	
	static int select=0;
	int pressed=0;
	int distanza=0;
	
	if((LPC_GPIO1->FIOPIN & (1<<25)) == 0 && win==0){	
		/* Joytick select pressed */
		select++;
		switch(select){
			case 1:
				mode=!mode;
				cambia_colore(mode); //cambio colore del robot
				break;
			default:
				break;
		}
	}
	else{
			select=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<26)) == 0 && win==0){
		pressed=1;
		direzione='S';
	}
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0 && win==0){
		pressed=1;
		direzione='O';
	}
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0 && win==0){
		pressed=1;
		direzione='E';
	}
	if((LPC_GPIO1->FIOPIN & (1<<29)) == 0 && win==0){
		pressed=1;
		direzione='N';
	}
	
	if(pressed==1){
		count++;
		if(count>20 && count%20==0){
			if(mode==0){
				avanza(); //se possibile muovo il robot
				distanza=calcola_distanza(); //se trovato, ritorna la distanza dell'ostacolo
				if(win==1){ //gestione della vittoria
					vittoria();
				}
				if(distanza!=0 && win==0){
					aggiorna_ostacoli(distanza); //controlla se l'ostacolo è gia stato stampato, altrimenti lo stampa
				}
			}
		}
	if(count==1){
			if(mode==1){
				ruota_robot(); //cambio l'orientazione del robot sulla mappa
				distanza=calcola_distanza(); //se trovato, ritorna la distanza dell'ostacolo
				if(distanza!=0){
					aggiorna_ostacoli(distanza); //controlla se l'ostacolo è gia stato stampato, altrimenti lo stampa
				}
			}
		}
	}
	else {
		count=0;
	}	
	
	
	/* Button management potrebbe tornare utile come funzione di libreria
	if(down!=0){ 
		if((LPC_GPIO2->FIOPIN & (1<<11)) == 0){	// KEY1 pressed 
			down++;				
			switch(down){
				case 2:				// pay attention here: please see slides 19_ to understand value 2 
				if( position == 7){
					LED_On(0);
					LED_Off(7);
					position = 0;
				}
				else{
					LED_Off(position);
					LED_On(++position);
				}
					break;
				default:
					break;
			}
		}
		else {	// button released 
			down=0;			
			NVIC_EnableIRQ(EINT1_IRQn);							 // enable Button interrupts			
			LPC_PINCON->PINSEL4    |= (1 << 22);     // External interrupt 0 pin selection 
		}
	} */
	
	disable_RIT();
	reset_RIT();
	enable_RIT();
	
  LPC_RIT->RICTRL |= 0x1;	// clear interrupt flag 
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
