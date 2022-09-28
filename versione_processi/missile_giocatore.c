/* Funzione missile del giocatore */

#include "missile_giocatore.h"

void sparo(int pipeout, int y, int direzione, int colpo){

	struct oggetto sparo; 	//inizializzo missile giocatore

	int cicli = 0;			//variabile per determinare il movimento verticale dello sparo

	/* Inizializzo dati del missile del giocatore */
	sparo.y=y;
	sparo.sprite='s';
	sparo.pid=getpid();		
	sparo.vite=0;

	write(pipeout, &sparo, sizeof(sparo));

	sparo.x=6;		//posizione orizontale di partenza del missile

	/** Ciclo per la funzionalità di sparo dalla nave (quale missile generare)
	 *  Ogni coppia di missili pari usa come identificatori i caratteri : e ;
	 * 	Quelli dispari utilizzano come identificatori . e ,	*/

	switch(colpo){
		
		case 0:

			//Finchè lo sparo è nell'area di gioco si muove
			while(sparo.x > 0 && sparo.y > 2 && sparo.x < MAXX && sparo.y < MAXY){

				//Direzione in alto
				if(direzione==1){

					sparo.sprite=',';	//carattere di risconoscimento dello sparo

					/* Muovo il missile per 5 colonne , poi 1 riga in verticale */
					if(cicli == 5){

						sparo.x++;
						sparo.y--;
						cicli = 0;

					} else {

						sparo.x++;
						cicli++;						
					}

					write(pipeout, &sparo, sizeof(sparo));

					usleep(25000);
				}

				//Direzione in basso
				if(direzione==0){

					sparo.sprite='.';	//carattere di risconoscimento dello sparo

					if(cicli == 5){

						sparo.x++;
						sparo.y++;
						cicli = 0;

					} else {

						sparo.x++;
						cicli++;						
					}

					write(pipeout, &sparo, sizeof(sparo));
					usleep(25000);
				}
			}
			break;

		case 1:

			while(sparo.x>0&&sparo.y>2&&sparo.x<MAXX&&sparo.y<MAXY){

				if(direzione==1){

					sparo.sprite=';';

					if(cicli == 5){

						sparo.x++;
						sparo.y--;
						cicli = 0;

					} else {

						sparo.x++;
						cicli++;						
					}

					write(pipeout, &sparo, sizeof(sparo));
					usleep(25000);
				}

				if(direzione==0){

					sparo.sprite=':';

					if(cicli == 5){

						sparo.x++;
						sparo.y++;
						cicli = 0;

					} else {

						sparo.x++;
						cicli++;						
					}

					write(pipeout, &sparo, sizeof(sparo));
					usleep(25000);
					
				}
			}
			
			break;
	}
};
