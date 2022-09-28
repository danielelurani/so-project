/* Funzioni di controllo */

#include "controllo.h"

long timevaldiff(struct timeval *t1, struct timeval *t2)
{
	long msec;
	msec = (t2->tv_sec - t1->tv_sec) * 1000;
	msec += (t2->tv_usec - t1->tv_usec) / 1000;
	
	return msec;
}


void controllo(){

	// Buffer per stampare stringhe
	char buffer[512];

	//Contatore per cicli for utilizzati, contatore del punteggio e vettore per controllare le vite degli alieni di livello 2
	int c, navi_distrutte, vittoria=0;
	navi_distrutte=0;

	do{
		/**Controllo collisioni alieni con missili del giocatore
		 * Quando i missili si scontrano con un alieno, vengono spostati fuori dall'area di gioco terminandosi
		 * Quando una nave aliena viene colpita, ne riduciamo le vite per simulare il cambiamento di livello
		 * */
	
			for(c=0;c<MAXALIENI-MINALIENI;c++){

				if((shot1.x==al[c].x&&shot1.y==al[c].y+1)||
					(shot1.x==al[c].x+1&&shot1.y==al[c].y+1)||
					(shot1.x==al[c].x+2&&shot1.y==al[c].y+1)||
					(shot1.x==al[c].x+5&&shot1.y==al[c].y+1)||
					(shot1.x==al[c].x+6&&shot1.y==al[c].y+1)||
					(shot1.x==al[c].x+7&&shot1.y==al[c].y+1)||
					(shot1.x==al[c].x&&shot1.y==al[c].y-1)||
					(shot1.x==al[c].x+1&&shot1.y==al[c].y-1)||
					(shot1.x==al[c].x+2&&shot1.y==al[c].y-1)||
					(shot1.x==al[c].x+5&&shot1.y==al[c].y-1)||
					(shot1.x==al[c].x+6&&shot1.y==al[c].y-1)||
					(shot1.x==al[c].x+7&&shot1.y==al[c].y-1)){

					navi_distrutte++;
					shot1.x=150;
					shot1.y=90;
					al[c].vite--;
					if(al[c].vite==0){	//Quando un alieno viene colpito 3 volte viene cancellato

						pthread_mutex_lock(&mutex);

						mvaddch(al[c].y, al[c].x, ' ');
						mvaddch(al[c].y, al[c].x+1, ' ');
						mvaddch(al[c].y, al[c].x+2, ' ');
						mvaddch(al[c].y, al[c].x+3, ' ');
						mvaddch(al[c].y, al[c].x+4, ' ');
						mvaddch(al[c].y, al[c].x+5, ' ');

						mvaddch(al[c].y+1, al[c].x+2, ' ');
						mvaddch(al[c].y+1, al[c].x+3, ' ');
						mvaddch(al[c].y+1, al[c].x+4, ' ');
						mvaddch(al[c].y+1, al[c].x+5, ' ');

						mvaddch(al[c].y-1, al[c].x+2, ' ');
						mvaddch(al[c].y-1, al[c].x+3, ' ');
						mvaddch(al[c].y-1, al[c].x+4, ' ');
						mvaddch(al[c].y-1, al[c].x+5, ' ');
			
						//cancello vecchia posizione alieni livello 2
						mvaddch(al[c].y-1, al[c].x, ' ');
						mvaddch(al[c].y-1, al[c].x+1, ' ');
						mvaddch(al[c].y-1, al[c].x+2, ' ');
						mvaddch(al[c].y-1, al[c].x+3, ' ');
						mvaddch(al[c].y-1, al[c].x+4, ' ');
						mvaddch(al[c].y-1, al[c].x+5, ' ');
						mvaddch(al[c].y-1, al[c].x+6, ' ');
						mvaddch(al[c].y-1, al[c].x+7, ' ');
						mvaddch(al[c].y-1, al[c].x+8, ' ');

						mvaddch(al[c].y+1, al[c].x, ' ');
						mvaddch(al[c].y+1, al[c].x+1, ' ');
						mvaddch(al[c].y+1, al[c].x+2, ' ');
						mvaddch(al[c].y+1, al[c].x+3, ' ');
						mvaddch(al[c].y+1, al[c].x+4, ' ');
						mvaddch(al[c].y+1, al[c].x+5, ' ');
						mvaddch(al[c].y+1, al[c].x+6, ' ');
						mvaddch(al[c].y+1, al[c].x+7, ' ');
						mvaddch(al[c].y+1, al[c].x+8, ' ');

						pthread_mutex_unlock(&mutex);

						al[c].y=50;
					}

				}

				if((shot2.x==al[c].x&&shot2.y==al[c].y+1)||
					(shot2.x==al[c].x+1&&shot2.y==al[c].y+1)||
					(shot2.x==al[c].x+2&&shot2.y==al[c].y+1)||
					(shot2.x==al[c].x+5&&shot2.y==al[c].y+1)||
					(shot2.x==al[c].x+6&&shot2.y==al[c].y+1)||
					(shot2.x==al[c].x+7&&shot2.y==al[c].y+1)||
					(shot2.x==al[c].x&&shot2.y==al[c].y-1)||
					(shot2.x==al[c].x+1&&shot2.y==al[c].y-1)||
					(shot2.x==al[c].x+2&&shot2.y==al[c].y-1)||
					(shot2.x==al[c].x+5&&shot2.y==al[c].y-1)||
					(shot2.x==al[c].x+6&&shot2.y==al[c].y-1)||
					(shot2.x==al[c].x+7&&shot2.y==al[c].y-1)){

					navi_distrutte++;
					shot2.x=150;
					shot2.y=90;
					al[c].vite--;
					if(al[c].vite==0){
						
						pthread_mutex_lock(&mutex);

						mvaddch(al[c].y, al[c].x, ' ');
						mvaddch(al[c].y, al[c].x+1, ' ');
						mvaddch(al[c].y, al[c].x+2, ' ');
						mvaddch(al[c].y, al[c].x+3, ' ');
						mvaddch(al[c].y, al[c].x+4, ' ');
						mvaddch(al[c].y, al[c].x+5, ' ');

						mvaddch(al[c].y+1, al[c].x+2, ' ');
						mvaddch(al[c].y+1, al[c].x+3, ' ');
						mvaddch(al[c].y+1, al[c].x+4, ' ');
						mvaddch(al[c].y+1, al[c].x+5, ' ');

						mvaddch(al[c].y-1, al[c].x+2, ' ');
						mvaddch(al[c].y-1, al[c].x+3, ' ');
						mvaddch(al[c].y-1, al[c].x+4, ' ');
						mvaddch(al[c].y-1, al[c].x+5, ' ');
			
						//cancello vecchia posizione alieni livello 2
						mvaddch(al[c].y-1, al[c].x, ' ');
						mvaddch(al[c].y-1, al[c].x+1, ' ');
						mvaddch(al[c].y-1, al[c].x+2, ' ');
						mvaddch(al[c].y-1, al[c].x+3, ' ');
						mvaddch(al[c].y-1, al[c].x+4, ' ');
						mvaddch(al[c].y-1, al[c].x+5, ' ');
						mvaddch(al[c].y-1, al[c].x+6, ' ');
						mvaddch(al[c].y-1, al[c].x+7, ' ');
						mvaddch(al[c].y-1, al[c].x+8, ' ');

						mvaddch(al[c].y+1, al[c].x, ' ');
						mvaddch(al[c].y+1, al[c].x+1, ' ');
						mvaddch(al[c].y+1, al[c].x+2, ' ');
						mvaddch(al[c].y+1, al[c].x+3, ' ');
						mvaddch(al[c].y+1, al[c].x+4, ' ');
						mvaddch(al[c].y+1, al[c].x+5, ' ');
						mvaddch(al[c].y+1, al[c].x+6, ' ');
						mvaddch(al[c].y+1, al[c].x+7, ' ');
						mvaddch(al[c].y+1, al[c].x+8, ' ');

						pthread_mutex_unlock(&mutex);

						al[c].y=50;
					}

				}

				if((shot3.x==al[c].x&&shot3.y==al[c].y+1)||
					(shot3.x==al[c].x+1&&shot3.y==al[c].y+1)||
					(shot3.x==al[c].x+2&&shot3.y==al[c].y+1)||
					(shot3.x==al[c].x+5&&shot3.y==al[c].y+1)||
					(shot3.x==al[c].x+6&&shot3.y==al[c].y+1)||
					(shot3.x==al[c].x+7&&shot3.y==al[c].y+1)||
					(shot3.x==al[c].x&&shot3.y==al[c].y-1)||
					(shot3.x==al[c].x+1&&shot3.y==al[c].y-1)||
					(shot3.x==al[c].x+2&&shot3.y==al[c].y-1)||
					(shot3.x==al[c].x+5&&shot3.y==al[c].y-1)||
					(shot3.x==al[c].x+6&&shot3.y==al[c].y-1)||
					(shot3.x==al[c].x+7&&shot3.y==al[c].y-1)){

					navi_distrutte++;
					shot3.x=150;
					shot3.y=90;
					al[c].vite--;
					if(al[c].vite==0){

						pthread_mutex_lock(&mutex);

						mvaddch(al[c].y, al[c].x, ' ');
						mvaddch(al[c].y, al[c].x+1, ' ');
						mvaddch(al[c].y, al[c].x+2, ' ');
						mvaddch(al[c].y, al[c].x+3, ' ');
						mvaddch(al[c].y, al[c].x+4, ' ');
						mvaddch(al[c].y, al[c].x+5, ' ');

						mvaddch(al[c].y+1, al[c].x+2, ' ');
						mvaddch(al[c].y+1, al[c].x+3, ' ');
						mvaddch(al[c].y+1, al[c].x+4, ' ');
						mvaddch(al[c].y+1, al[c].x+5, ' ');

						mvaddch(al[c].y-1, al[c].x+2, ' ');
						mvaddch(al[c].y-1, al[c].x+3, ' ');
						mvaddch(al[c].y-1, al[c].x+4, ' ');
						mvaddch(al[c].y-1, al[c].x+5, ' ');
			
						//cancello vecchia posizione alieni livello 2
						mvaddch(al[c].y-1, al[c].x, ' ');
						mvaddch(al[c].y-1, al[c].x+1, ' ');
						mvaddch(al[c].y-1, al[c].x+2, ' ');
						mvaddch(al[c].y-1, al[c].x+3, ' ');
						mvaddch(al[c].y-1, al[c].x+4, ' ');
						mvaddch(al[c].y-1, al[c].x+5, ' ');
						mvaddch(al[c].y-1, al[c].x+6, ' ');
						mvaddch(al[c].y-1, al[c].x+7, ' ');
						mvaddch(al[c].y-1, al[c].x+8, ' ');

						mvaddch(al[c].y+1, al[c].x, ' ');
						mvaddch(al[c].y+1, al[c].x+1, ' ');
						mvaddch(al[c].y+1, al[c].x+2, ' ');
						mvaddch(al[c].y+1, al[c].x+3, ' ');
						mvaddch(al[c].y+1, al[c].x+4, ' ');
						mvaddch(al[c].y+1, al[c].x+5, ' ');
						mvaddch(al[c].y+1, al[c].x+6, ' ');
						mvaddch(al[c].y+1, al[c].x+7, ' ');
						mvaddch(al[c].y+1, al[c].x+8, ' ');

						pthread_mutex_unlock(&mutex);

						al[c].y=50;
					}
				}

				if((shot4.x==al[c].x&&shot4.y==al[c].y+1)||
					(shot4.x==al[c].x+1&&shot4.y==al[c].y+1)||
					(shot4.x==al[c].x+2&&shot4.y==al[c].y+1)||
					(shot4.x==al[c].x+5&&shot4.y==al[c].y+1)||
					(shot4.x==al[c].x+6&&shot4.y==al[c].y+1)||
					(shot4.x==al[c].x+7&&shot4.y==al[c].y+1)||
					(shot4.x==al[c].x&&shot4.y==al[c].y-1)||
					(shot4.x==al[c].x+1&&shot4.y==al[c].y-1)||
					(shot4.x==al[c].x+2&&shot4.y==al[c].y-1)||
					(shot4.x==al[c].x+5&&shot4.y==al[c].y-1)||
					(shot4.x==al[c].x+6&&shot4.y==al[c].y-1)||
					(shot4.x==al[c].x+7&&shot4.y==al[c].y-1)){

					navi_distrutte++;
					shot4.x=150;
					shot4.y=90;
					al[c].vite--;
					if(al[c].vite==0){

						pthread_mutex_lock(&mutex);

						mvaddch(al[c].y, al[c].x, ' ');
						mvaddch(al[c].y, al[c].x+1, ' ');
						mvaddch(al[c].y, al[c].x+2, ' ');
						mvaddch(al[c].y, al[c].x+3, ' ');
						mvaddch(al[c].y, al[c].x+4, ' ');
						mvaddch(al[c].y, al[c].x+5, ' ');

						mvaddch(al[c].y+1, al[c].x+2, ' ');
						mvaddch(al[c].y+1, al[c].x+3, ' ');
						mvaddch(al[c].y+1, al[c].x+4, ' ');
						mvaddch(al[c].y+1, al[c].x+5, ' ');

						mvaddch(al[c].y-1, al[c].x+2, ' ');
						mvaddch(al[c].y-1, al[c].x+3, ' ');
						mvaddch(al[c].y-1, al[c].x+4, ' ');
						mvaddch(al[c].y-1, al[c].x+5, ' ');
			
						//cancello vecchia posizione alieni livello 2
						mvaddch(al[c].y-1, al[c].x, ' ');
						mvaddch(al[c].y-1, al[c].x+1, ' ');
						mvaddch(al[c].y-1, al[c].x+2, ' ');
						mvaddch(al[c].y-1, al[c].x+3, ' ');
						mvaddch(al[c].y-1, al[c].x+4, ' ');
						mvaddch(al[c].y-1, al[c].x+5, ' ');
						mvaddch(al[c].y-1, al[c].x+6, ' ');
						mvaddch(al[c].y-1, al[c].x+7, ' ');
						mvaddch(al[c].y-1, al[c].x+8, ' ');

						mvaddch(al[c].y+1, al[c].x, ' ');
						mvaddch(al[c].y+1, al[c].x+1, ' ');
						mvaddch(al[c].y+1, al[c].x+2, ' ');
						mvaddch(al[c].y+1, al[c].x+3, ' ');
						mvaddch(al[c].y+1, al[c].x+4, ' ');
						mvaddch(al[c].y+1, al[c].x+5, ' ');
						mvaddch(al[c].y+1, al[c].x+6, ' ');
						mvaddch(al[c].y+1, al[c].x+7, ' ');
						mvaddch(al[c].y+1, al[c].x+8, ' ');

						pthread_mutex_unlock(&mutex);

						al[c].y=50;
					}

				}

			}
	
	//Controllo collisioni navi aliene con la nave del giocatore
	for(c=0;c<MAXALIENI-MINALIENI;c++){

			if((al[c].x+2==nav.x-1&&al[c].y+1==nav.y+2)||
				(al[c].x+3==nav.x-1&&al[c].y+1==nav.y+2)||
				(al[c].x+4==nav.x-1&&al[c].y+1==nav.y+2)||
				(al[c].x+5==nav.x-1&&al[c].y+1==nav.y+2)||
				(al[c].x+6==nav.x-1&&al[c].y+1==nav.y+2)||

				(al[c].x+2==nav.x-1&&al[c].y+1==nav.y-2)||
				(al[c].x+3==nav.x-1&&al[c].y+1==nav.y-2)||
				(al[c].x+4==nav.x-1&&al[c].y+1==nav.y-2)||
				(al[c].x+5==nav.x-1&&al[c].y+1==nav.y-2)||
				(al[c].x+6==nav.x-1&&al[c].y+1==nav.y-2)||

				(al[c].x+2==nav.x-1&&al[c].y-1==nav.y-2)||
				(al[c].x+3==nav.x-1&&al[c].y-1==nav.y-2)||
				(al[c].x+4==nav.x-1&&al[c].y-1==nav.y-2)||
				(al[c].x+5==nav.x-1&&al[c].y-1==nav.y-2)||
				(al[c].x+6==nav.x-1&&al[c].y-1==nav.y-2)||
			
				(al[c].x+2==nav.x-1&&al[c].y-1==nav.y+2)||
				(al[c].x+3==nav.x-1&&al[c].y-1==nav.y+2)||
				(al[c].x+4==nav.x-1&&al[c].y-1==nav.y+2)||
				(al[c].x+5==nav.x-1&&al[c].y-1==nav.y+2)||
				(al[c].x+6==nav.x-1&&al[c].y-1==nav.y+2)||

				(al[c].x==nav.x-1&&al[c].y==nav.y)||
				(al[c].x==nav.x&&al[c].y==nav.y+2)||
				(al[c].x==nav.x&&al[c].y==nav.y-2)||
				(al[c].x==nav.x&&al[c].y==nav.y+1)||
				(al[c].x==nav.x&&al[c].y==nav.y-1)||
				(al[c].x==nav.x-1&&al[c].y==nav.y-2)||
				(al[c].x==nav.x-1&&al[c].y==nav.y+2)||
				(al[c].x==nav.x-1&&al[c].y==nav.y+1)||
				(al[c].x==nav.x-1&&al[c].y==nav.y-1)||
			
				(al[c].x==nav.x&&al[c].y==nav.y+2)||
				(al[c].x-1==nav.x-1&&al[c].y==nav.y+2)||
				(al[c].x-2==nav.x-1&&al[c].y==nav.y+2)||
				(al[c].x==nav.x&&al[c].y==nav.y)){

				vite=0;
			}
	}
	
	//Controllo collisioni navi giocatore con le bombe aliene
	for(c=0;c<MAXALIENI-MINALIENI;c++){
		
		if(bomba[c].x==nav.x-2&&bomba[c].y==nav.y+1){

			vite=0;
		}

		if(bomba[c].x==nav.x-2&&bomba[c].y==nav.y-1){

			vite=0;
		}

		if(bomba[c].x==nav.x-1&&bomba[c].y==nav.y+2){

			vite=0;
		}

		if(bomba[c].x==nav.x-1&&bomba[c].y==nav.y-2){

			vite=0;
		}
		
		if(bomba[c].x==nav.x&&bomba[c].y==nav.y){

			vite=0;
		}
		if(bomba[c].x==nav.x-1&&bomba[c].y==nav.y){

			vite=0;
		}
		if(bomba[c].x==nav.x-2&&bomba[c].y==nav.y){

			vite=0;
		}
		if(bomba[c].x==nav.x-3&&bomba[c].y==nav.y){

			vite=0;
		}
		if(bomba[c].x==nav.x-4&&bomba[c].y==nav.y){

			vite=0;
		}
	}

	//Quando tutte le navi aliene vengono distrutte, finisce il gioco e si vince
	if(navi_distrutte==(MAXALIENI-MINALIENI)*3){
		vittoria=1;
		vite=0;
	}
	
	//Se una nave nemica arriva al lato sinistro dello schermo il giocatore perde		
	for(c=0;c<MAXALIENI-MINALIENI;c++){

		if(al[c].x==0){

			vite=0;

		}

	}

	pthread_mutex_lock(&mutex);

	/* stampa delimitazione area di gioco */
	int counter;

	mvaddch(0, 0, ACS_ULCORNER);
	mvaddch(MAXY, 0, ACS_LLCORNER);

	mvaddch(0, MAXX, ACS_URCORNER);
	mvaddch(MAXY, MAXX, ACS_LRCORNER);	
	
	for(counter = 1; counter < MAXX; counter++){
		mvaddch(0, counter, ACS_HLINE);
		mvaddch(MAXY, counter, ACS_HLINE);
	}

	for(counter = 1; counter < MAXY; counter++){
		mvaddch(counter, 0, ACS_VLINE);
		mvaddch(counter, MAXX, ACS_VLINE);
	}

	refresh();
	pthread_mutex_unlock(&mutex);

	//chiudi il gioco se il giocatore preme 0
	if(nav.sprite=='0'){
		vite=0;
	}

	}while(vite>0);

	//ritorna il risultato del gioco (1 vittoria, 0 sconfitta)
	endwin();
	if(vittoria==1){printf("\n\n\n\n HAI VINTO \n\n\n\n");}
	else{printf("\n\n\n\n HAI PERSO \n\n\n\n");}
};
