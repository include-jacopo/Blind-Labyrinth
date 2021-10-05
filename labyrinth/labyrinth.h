/**--------------File Info---------------------------------------------------------------------------------
** File name:           labyrinth.h
** Last modified Date:  2021-01-05
** Last Version:        V1.00
** Descriptions:        Extrapoint1 di Pati Jacopo
** Correlated files:    labyrinth.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

extern int x;
extern int y;
extern int win;
extern char direzione;
int calcola_distanza(void);
void start_labirinto(void);
void ruota_robot(void);
void avanza(void);
void pulisci_ostacoli(void);
void aggiorna_ostacoli(int dist);
void cambia_colore(int mode);
void vittoria(void);
