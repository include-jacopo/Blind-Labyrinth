/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include <string.h>
#include "lpc17xx.h"
#include "timer.h"
#include "../GLCD/GLCD.h" 
#include "../TouchPanel/TouchPanel.h"
#include "../display/display.h"
#include "../labyrinth/labyrinth.h"
#include "../RIT/RIT.h"

/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

void TIMER0_IRQHandler (void)
{
	static int start=0;
	int distanza=0;
	
	getDisplayPoint(&display, Read_Ads7846(), &matrix );
	
	if(start==0 && display.x <= 232 && display.x > 7){ //abilitazione gioco
		if(display.y < 257 && display.x > 98){
			win=0;
			start=1;
			cancella_scritta(); //elimina la scritta "touch to start a new game"
			start_labirinto(); //inizializza il robot in 7x7 E
		}
	LPC_TIM0->IR = 1;			// clear interrupt flag 
  return;
	}
	
	if(start==1 && display.x <= 110 && display.x > 7){ //lettura touch RESTART
		start=0;
		if(win==0){
			pulisci_ostacoli(); //chiamata alla funzione che cancella gli eventuali ostacoli già presenti
			cancella_cella(x,y); //funzione che cancella il robot;
			scritta_iniziale(); 
		}
		if(win==1){
			inizializza_sfondo(); //funzione che stampa nuovamente il quadrato bianco di sfondo
			pulisci_ostacoli(); //chiamata alla funzione che cancella gli eventuali ostacoli già presenti
			scritta_iniziale();
		}
	LPC_TIM0->IR = 1;			// clear interrupt flag 
  return;
	}
	
	if(start==1 && display.x <= 233 && display.x > 130){ //lettura touch CLEAR
		if(win==0){
				pulisci_ostacoli();
				distanza=calcola_distanza(); //se trovato, ritorna la distanza dell'ostacolo
				if(distanza!=0){
					aggiorna_ostacoli(distanza); //controlla se l'ostacolo è gia stato stampato, altrimenti lo stampa
				}
	}

	LPC_TIM0->IR = 1;			// clear interrupt flag 
  return;
	}
	
	LPC_TIM0->IR = 1;			// clear interrupt flag 
  return;

	
//FUNZIONE DEFAULT CON GESTIONE CLICK PROLUNGAT0, LA LASCIO COME EVENTUALE LIBRERIA	
/*	static int clear = 0;
	char time_in_char[5] = "";
	 
	getDisplayPoint(&display, Read_Ads7846(), &matrix ) ;
	if(display.x <= 240 && display.x > 0){
		if(display.y < 280){
			TP_DrawPoint(display.x,display.y);
			GUI_Text(200, 0, (uint8_t *) "     ", Blue, Blue);
			clear = 0;
		}
		else{		
			if(display.y <= 0x13E){			
				clear++;
				if(clear%20 == 0){
					sprintf(time_in_char,"%4d",clear/20);
					GUI_Text(200, 0, (uint8_t *) time_in_char, White, Blue);
					if(clear == 200){	// 1 seconds = 200 times * 500 us
						LCD_Clear(Blue);
						GUI_Text(0, 280, (uint8_t *) " touch here : 1 sec to clear ", Blue, White);			
						clear = 0;
					}
				}
			}
		}
	}
	else{
		//do nothing if touch returns values out of bounds
	} */

}

/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER1_IRQHandler (void)
{
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
