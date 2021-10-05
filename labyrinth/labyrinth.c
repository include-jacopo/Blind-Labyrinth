
#include "labyrinth.h"
#include "../display/display.h"

int x;
int y;
int win;

char direzione;

int lab[13][15] = {
{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
{0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},																				 
{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},																									 
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},																		 
{2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
}; 

int ostacoli[13][15] = {
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},																				 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},																									 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},																		 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
}; 

int calcola_distanza(void){ //funzione che ritorna la distanza dall'ostacolo
	
	int dist_ostacolo;
	
	if(lab[y][x]==2){ //gestione della vittoria
		win=1;
		return 9;
	}
	
	if(direzione=='N'){
		if(y>0 && lab[y-1][x]!=1){
			if(y-2>=0 && lab[y-2][x]==1){
				dist_ostacolo=2;
				return dist_ostacolo;
			}
			if(y-3>=0 && lab[y-3][x]==1){
				dist_ostacolo=3;
				return dist_ostacolo;
			}
			if(y-4>=0 && lab[y-4][x]==1){
				dist_ostacolo=4;
				return dist_ostacolo;
			}
			if(y-5>=0 && lab[y-5][x]==1){
				dist_ostacolo=5;
				return dist_ostacolo;
			}
		}
		if(y>0 && lab[y-1][x]==1){
				dist_ostacolo=1;
				return dist_ostacolo;
			}
	dist_ostacolo=0;
	return dist_ostacolo;
	}
	
	if(direzione=='S'){
		if(y<12 && lab[y+1][x]!=1){
			if(y+2<=12 && lab[y+2][x]==1){
				dist_ostacolo=2;
				return dist_ostacolo;
			}
			if(y+3<=12 && lab[y+3][x]==1){
				dist_ostacolo=3;
				return dist_ostacolo;
			}
			if(y+4<=12 && lab[y+4][x]==1){
				dist_ostacolo=4;
				return dist_ostacolo;
			}
			if(y+5<=12 && lab[y+5][x]==1){
				dist_ostacolo=5;
				return dist_ostacolo;
			}
		}
		if(y<12 && lab[y+1][x]==1){
			dist_ostacolo=1;
			return dist_ostacolo;
		}
	dist_ostacolo=0;
	return dist_ostacolo;
	}
		
	if(direzione=='E'){
			if(x<14 && lab[y][x+1]!=1){
				if(x+2<=14 && lab[y][x+2]==1){
					dist_ostacolo=2;
					return dist_ostacolo;
				}
				if(x+3<=14 && lab[y][x+3]==1){
					dist_ostacolo=3;
					return dist_ostacolo;
				}
				if(x+4<=14 && lab[y][x+4]==1){
					dist_ostacolo=4;
					return dist_ostacolo;
				}
				if(x+5<=14 && lab[y][x+5]==1){
					dist_ostacolo=5;
					return dist_ostacolo;
				}
			}
			if(x<14 && lab[y][x+1]==1){
				dist_ostacolo=1;
				return dist_ostacolo;
			}
		dist_ostacolo=0;
		return dist_ostacolo;
	}
	
	if(direzione=='O'){
			if(x>0 && lab[y][x-1]!=1){
				if(x-2>=0 && lab[y][x-2]==1){
					dist_ostacolo=2;
					return dist_ostacolo;
				}
				if(x-3>=0 && lab[y][x-3]==1){
					dist_ostacolo=3;
					return dist_ostacolo;
				}
				if(x-4>=0 && lab[y][x-4]==1){
					dist_ostacolo=4;
					return dist_ostacolo;
				}
				if(x-5>=0 && lab[y][x-5]==1){
					dist_ostacolo=5;
					return dist_ostacolo;
				}
		}
		if(x>0 && lab[y][x-1]==1){
				dist_ostacolo=1;
				return dist_ostacolo;
		}
	dist_ostacolo=0;
	return dist_ostacolo;
	}
	return 0;
}


void avanza (void){
	
	if(direzione=='N'){
		if(y>0 && lab[y-1][x]!=1){
			cancella_cella(x,y);
			y--; //muovo
			disegna_robot(x,y,direzione);
		}
		if(y>0 && lab[y-1][x]==1){
			cancella_cella(x,y);
			disegna_robot(x,y,direzione);
		}
	}
	
	if(direzione=='S'){
		if(y<12 && lab[y+1][x]!=1){
			cancella_cella(x,y);
			y++; //muovo
			disegna_robot(x,y,direzione);
		}
		if(y<12 && lab[y+1][x]==1){
			cancella_cella(x,y);
			disegna_robot(x,y,direzione);
		}
	}
		
	if(direzione=='E'){
			if(x<14 && lab[y][x+1]!=1){
			cancella_cella(x,y);
			x++; //muovo
			disegna_robot(x,y,direzione);
		}
			if(x<14 && lab[y][x+1]==1){
			cancella_cella(x,y);
			disegna_robot(x,y,direzione);
		}
	}
	
	if(direzione=='O'){
			if(x>0 && lab[y][x-1]!=1){
				cancella_cella(x,y);
				x--; //muovo
				disegna_robot(x,y,direzione);
			}
			if(x>0 && lab[y][x-1]==1){
				cancella_cella(x,y);
				disegna_robot(x,y,direzione);
			}
	}
	return;
}



void start_labirinto(void){
	x=7;
	y=7;
	direzione='E';
	disegna_robot(x,y,direzione);
}

void ruota_robot(void){
	cancella_cella(x,y);
	disegna_robot_verde(x,y,direzione);
	return;
}

void pulisci_ostacoli(void){
	int i, j;
	for(i=0;i<12;i++){
		for(j=0; j<14; j++){
			if(ostacoli[j][i]==1){
				ostacoli[j][i]=0;
				cancella_cella(j,i);
			}
		}
	}
}

void aggiorna_ostacoli(int dist){
	if(direzione=='E'){
		if(ostacoli[x+dist][y]==0){
			ostacoli[x+dist][y]=1;
			disegna_cella(x+dist,y);
		}
	}
	if(direzione=='O'){
		if(ostacoli[x-dist][y]==0){
			ostacoli[x-dist][y]=1;
			disegna_cella(x-dist,y);
		}
	}
	if(direzione=='N'){
		if(ostacoli[x][y-dist]==0){
			ostacoli[x][y-dist]=1;
			disegna_cella(x,y-dist);
		}
	}
	if(direzione=='S'){
		if(ostacoli[x][y+dist]==0){
			ostacoli[x][y+dist]=1;
			disegna_cella(x,y+dist);
		}
	}
	return;
}

void cambia_colore(int mode){
	if(mode==0){
		cancella_cella(x,y);
		disegna_robot(x,y,direzione);
	}
	if(mode==1){
		cancella_cella(x,y);
		disegna_robot_verde(x,y,direzione);
	}
}

void vittoria(void){
	stampa_vittoria();
}
