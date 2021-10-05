
#include "display.h"
#include "../GLCD/GLCD.h" 
#include "../TouchPanel/TouchPanel.h"

void disegna_cella(int var_x, int var_y){
	int bordo_x=7;
	int bordo_y=62;
	int i;
	int pos_x;
	int pos_y;
	
	pos_x = bordo_x + var_x*15;
	pos_y = bordo_y + var_y*15;
	
	for(i=0; i<15; i++){
		LCD_DrawLine(pos_x, pos_y+i, pos_x+15, pos_y+i, Blue);
	}
	return;
}

void cancella_cella(int var_x, int var_y){
	int bordo_x=7;
	int bordo_y=62;
	int i;
	int pos_x;
	int pos_y;
	
	pos_x = bordo_x + var_x*15;
	pos_y = bordo_y + var_y*15;
	
	for(i=0; i<15; i++){
		LCD_DrawLine(pos_x, pos_y+i, pos_x+15, pos_y+i, White);
	}
	return;
}

void disegna_robot(int var_x, int var_y, char direction){
	int bordo_x=7;
	int bordo_y=62;
	int i;
	int j;
	int pos_x;
	int pos_y;
	
	pos_x = bordo_x + var_x*15;
	pos_y = bordo_y + var_y*15;
	
	if(direction=='E'){
			for(i=0;i<=7;i++){
				LCD_DrawLine(pos_x, pos_y+i, pos_x+2*i, pos_y+i, Magenta);
			}
		//	LCD_DrawLine(pos_x, pos_y+7, pos_x+14, pos_y+7, Blue);
			j=0;
			for(i=6;i>=0;i--){
				LCD_DrawLine(pos_x, pos_y+8+j, pos_x+2*i, pos_y+8+j, Magenta);
				j++;
			}
			return;
	}
	if(direction=='O'){
			j=14;
			for(i=0;i<=7;i++){
				LCD_DrawLine(pos_x+j, pos_y+i, pos_x+14, pos_y+i, Magenta);
				j=j-2;
			}
			j=2;
			for(i=8;i<=14;i++){
				LCD_DrawLine(pos_x+j, pos_y+i, pos_x+14, pos_y+i, Magenta);
				j=j+2;
			}
			return;
	}
	if(direction=='S'){
			for(i=0;i<=7;i++){
				LCD_DrawLine(pos_x+i, pos_y, pos_x+i, pos_y+i*2, Magenta);
			}
			j=6;
			for(i=8;i<=14;i++){
				LCD_DrawLine(pos_x+i, pos_y, pos_x+i, pos_y+2*j, Magenta);
				j--;
			}
			return;
	}
	if(direction=='N'){
		j=0;
		for(i=0;i<=7;i++){
			LCD_DrawLine(pos_x+i, pos_y+14-j, pos_x+i, pos_y+14, Magenta);
			j=j+2;
		}
		j=2;
		for(i=8;i<=14;i++){
			LCD_DrawLine(pos_x+i, pos_y+j, pos_x+i, pos_y+14, Magenta);
			j=j+2;
		}
		return;
	}
}

void disegna_robot_verde(int var_x, int var_y, char direction){
	int bordo_x=7;
	int bordo_y=62;
	int i;
	int j;
	int pos_x;
	int pos_y;
	
	pos_x = bordo_x + var_x*15;
	pos_y = bordo_y + var_y*15;
	
	if(direction=='E'){
			for(i=0;i<=7;i++){
				LCD_DrawLine(pos_x, pos_y+i, pos_x+2*i, pos_y+i, Green);
			}
			j=0;
			for(i=6;i>=0;i--){
				LCD_DrawLine(pos_x, pos_y+8+j, pos_x+2*i, pos_y+8+j, Green);
				j++;
			}
			return;
	}
	if(direction=='O'){
			j=14;
			for(i=0;i<=7;i++){
				LCD_DrawLine(pos_x+j, pos_y+i, pos_x+14, pos_y+i, Green);
				j=j-2;
			}
			j=2;
			for(i=8;i<=14;i++){
				LCD_DrawLine(pos_x+j, pos_y+i, pos_x+14, pos_y+i, Green);
				j=j+2;
			}
			return;
	}
	if(direction=='S'){
			for(i=0;i<=7;i++){
				LCD_DrawLine(pos_x+i, pos_y, pos_x+i, pos_y+i*2, Green);
			}
			j=6;
			for(i=8;i<=14;i++){
				LCD_DrawLine(pos_x+i, pos_y, pos_x+i, pos_y+2*j, Green);
				j--;
			}
			return;
	}
	if(direction=='N'){
		j=0;
		for(i=0;i<=7;i++){
			LCD_DrawLine(pos_x+i, pos_y+14-j, pos_x+i, pos_y+14, Green);
			j=j+2;
		}
		j=2;
		for(i=8;i<=14;i++){
			LCD_DrawLine(pos_x+i, pos_y+j, pos_x+i, pos_y+14, Green);
			j=j+2;
		}
		return;
	}
}

void inizializza_sfondo(void){
	int x_0=7;
	int x_1=232;
	int y_0=62;
	int y_1=257;
	int i;
	int altezza=y_1-y_0;
	
	//matrice bianca 225x195
	//x parte da 7 e finisce a 232
	//y parte a 62 e finisce a 258
	
	for(i=0; i<altezza; i++){  //disegno sfondo bianco
		LCD_DrawLine(x_0, y_0+i, x_1, y_0+i,White);	
	}
}

void inizializza_interfaccia (void){
	int i;
	int altezza_tasto=30;
	int larghezza_tasto=103;

	LCD_Clear(Blue2); //disegno sfondo blu
	
	for(i=0; i<altezza_tasto; i++){  //sfondo tasti
		LCD_DrawLine(7, 270+i, larghezza_tasto, 270+i,White);	
		LCD_DrawLine(130, 270+i, 130+larghezza_tasto, 270+i,Yellow);
	} 
	
	GUI_Text(65, 25, (uint8_t *) "Blind Labyrith", White, Blue2); //testo tasti
	GUI_Text(7, 278, (uint8_t *) "  Restart ", Blue2, White);
	GUI_Text(130, 278, (uint8_t *) "    Clear  ", Blue2, Yellow);
	
	inizializza_sfondo(); //crea lo sfondo bianco del labirinto
	scritta_iniziale();
	return;
}

void scritta_iniziale(void){
	GUI_Text(87, 118, (uint8_t *) " Touch  ", Blue2, White);
	GUI_Text(87, 138, (uint8_t *) "to start  ", Blue2, White);
	GUI_Text(80, 158, (uint8_t *) "a new game", Blue2, White);
}

void cancella_scritta(void){
	GUI_Text(87, 118, (uint8_t *) " Touch  ", White, White);
	GUI_Text(87, 138, (uint8_t *) "to start  ", White, White);
	GUI_Text(80, 158, (uint8_t *) "a new game", White, White);
}

void stampa_vittoria(void){
		int pos_x, pos_y, var_x, var_y, i, j,k;
		int x_0=7;
		int x_1=232;
		int y_0=62;
		int y_1=257;
		int altezza=y_1-y_0;
	
	for(i=0; i<altezza; i++){  //disegno sfondo blu
		LCD_DrawLine(x_0, y_0+i, x_1, y_0+i,Blue2);	
	}
	
		GUI_Text(59, 118, (uint8_t *) "Thank you Mario!", White, Blue2);
		GUI_Text(53, 138, (uint8_t *) "Your quest is over", White, Blue2);
		GUI_Text(7, 158, (uint8_t *) "Press restart for a new game", White, Blue2);
		
		var_x = 9;
		var_y = 9; 
	
		pos_x = 7 + var_x*15;
		pos_y = 62 + var_y*15;
		j=0;
		for(i=0;i<=7;i++){
			LCD_DrawLine(pos_x+i, pos_y+14-j, pos_x+i, pos_y+14, Yellow);
			j=j+2;
		}
		j=2;
		for(i=8;i<=14;i++){
			LCD_DrawLine(pos_x+i, pos_y+j, pos_x+i, pos_y+14, Yellow);
			j=j+2;
		}
		
		var_x = 7;
		var_y = 9; 
	
		pos_x = 7 + var_x*15;
		pos_y = 62 + var_y*15;
		j=0;
		for(i=0;i<=7;i++){
			LCD_DrawLine(pos_x+i, pos_y+14-j, pos_x+i, pos_y+14, Yellow);
			j=j+2;
		}
		j=2;
		for(i=8;i<=14;i++){
			LCD_DrawLine(pos_x+i, pos_y+j, pos_x+i, pos_y+14, Yellow);
			j=j+2;
		}
		
		var_x = 5;
		var_y = 9; 
	
		pos_x = 7 + var_x*15;
		pos_y = 62 + var_y*15;
		j=0;
		for(i=0;i<=7;i++){
			LCD_DrawLine(pos_x+i, pos_y+14-j, pos_x+i, pos_y+14, Yellow);
			j=j+2;
		}
		j=2;
		for(i=8;i<=14;i++){
			LCD_DrawLine(pos_x+i, pos_y+j, pos_x+i, pos_y+14, Yellow);
			j=j+2;
		}
		
		for(j=5;j<10;j++){
			pos_x = 7 + j*15;
			pos_y = 62 + 10*15;
			for(k=0; k<15; k++){
				LCD_DrawLine(pos_x, pos_y+k, pos_x+15, pos_y+k, Yellow);
			}
		}
	}




