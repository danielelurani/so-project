/* Funzioni di controllo */

#include "controllo.h"

long timevaldiff(struct timeval *t1, struct timeval *t2)
{
	long msec;
	msec = (t2->tv_sec - t1->tv_sec) * 1000;
	msec += (t2->tv_usec - t1->tv_usec) / 1000;
	
	return msec;
}

int controllo(int pipein, int pipeout){

	//Contatore per cicli for utilizzati, contatore del punteggio e vettore per controllare le vite degli alieni di livello 2
	int c, navi_distrutte, colpi_alieno[25];

	/* Inizializzo ogni oggetto del gioco */
	struct oggetto nav, shot1, shot2, shot3, shot4, al[25], al2[25], valore_letto, bomba;

	int vittoria=0;
    nav.x=-1;
    shot1.x=-1;
	shot2.x=-1;
	shot3.x=-1;
	shot4.x=-1;

	for(c=0;c<26;c++){

		al[c].x = -1;
	}
	
	for(c=0;c<26;c++){

		al2[c].x = -1;
	}

	//Vite degli alieni di secondo livello
	for(c=0;c<26;c++){

		colpi_alieno[c]=1;
	}
	
	int vite = 1;	//variabile per la vita del gioco

	// Buffer per stampare stringhe
	char buffer[512];

	do{

		//Leggo dalla pipe 
		read(pipein, &valore_letto, sizeof(valore_letto));
		
		/**Controllo collisioni alieni livello 1 con missili del giocatore
		 * Quando i missili si scontrano con un alieno, esplodono e ne chiudiamo il processo
		 * Quando una nave aliena viene colpita, ne chiudiamo il processo
		 * */
		if(valore_letto.sprite == ',' || valore_letto.sprite == '.' || valore_letto.sprite == ';' || valore_letto.sprite == ':'){

			for(c=0;c<26;c++){

				if((valore_letto.x==al[c].x&&valore_letto.y==al[c].y)||
					(valore_letto.x==al[c].x+1&&valore_letto.y==al[c].y)||
					(valore_letto.x==al[c].x+2&&valore_letto.y==al[c].y)||
					(valore_letto.x==al[c].x+3&&valore_letto.y==al[c].y)||
					(valore_letto.x==al[c].x+4&&valore_letto.y==al[c].y)||
					(valore_letto.x==al[c].x+5&&valore_letto.y==al[c].y)||
					(valore_letto.x==al[c].x+6&&valore_letto.y==al[c].y)||
					(valore_letto.x==al[c].x+7&&valore_letto.y==al[c].y)||
					(valore_letto.x==al[c].x+2&&valore_letto.y==al[c].y+1)||
					(valore_letto.x==al[c].x+3&&valore_letto.y==al[c].y+1)||
					(valore_letto.x==al[c].x+4&&valore_letto.y==al[c].y+1)||
					(valore_letto.x==al[c].x+5&&valore_letto.y==al[c].y+1)||
					(valore_letto.x==al[c].x+6&&valore_letto.y==al[c].y+1)||
					(valore_letto.x==al[c].x+7&&valore_letto.y==al[c].y+1)||
					(valore_letto.x==al[c].x+2&&valore_letto.y==al[c].y-1)||
					(valore_letto.x==al[c].x+3&&valore_letto.y==al[c].y-1)||
					(valore_letto.x==al[c].x+4&&valore_letto.y==al[c].y-1)||
					(valore_letto.x==al[c].x+5&&valore_letto.y==al[c].y-1)||
					(valore_letto.x==al[c].x+6&&valore_letto.y==al[c].y-1)||
					(valore_letto.x==al[c].x+7&&valore_letto.y==al[c].y-1)){

					if(valore_letto.sprite==','){

						mvaddch(shot1.y, shot1.x, ' '); 
						mvaddch(shot1.y+1, shot1.x, ' '); 
						mvaddch(shot1.y-1, shot1.x, ' ');
						mvaddch(shot1.y, shot1.x+1, ' ');
						mvaddch(shot1.y, shot1.x-1, ' ');
						mvaddch(shot1.y+1, shot1.x+1, ' '); 
						mvaddch(shot1.y+1, shot1.x-1, ' ');
						mvaddch(shot1.y-1, shot1.x+1, ' '); 
						mvaddch(shot1.y-1, shot1.x-1, ' ');
						kill(shot1.pid, 1);
					}

					if(valore_letto.sprite=='.'){

						mvaddch(shot2.y, shot2.x, ' '); 
						mvaddch(shot2.y+1, shot2.x, ' '); 
						mvaddch(shot2.y-1, shot2.x, ' ');
						mvaddch(shot2.y, shot2.x+1, ' ');
						mvaddch(shot2.y, shot2.x-1, ' ');
						mvaddch(shot2.y+1, shot2.x+1, ' '); 
						mvaddch(shot2.y+1, shot2.x-1, ' ');
						mvaddch(shot2.y-1, shot2.x+1, ' '); 
						mvaddch(shot2.y-1, shot2.x-1, ' ');
						kill(shot2.pid, 1);
						}

					if(valore_letto.sprite==';'){

						mvaddch(shot3.y, shot3.x, ' '); 
						mvaddch(shot3.y+1, shot3.x, ' '); 
						mvaddch(shot3.y-1, shot3.x, ' ');
						mvaddch(shot3.y, shot3.x+1, ' ');
						mvaddch(shot3.y, shot3.x-1, ' ');
						mvaddch(shot3.y+1, shot3.x+1, ' '); 
						mvaddch(shot3.y+1, shot3.x-1, ' ');
						mvaddch(shot3.y-1, shot3.x+1, ' '); 
						mvaddch(shot3.y-1, shot3.x-1, ' ');
						kill(shot3.pid, 1);
					}

					if(valore_letto.sprite==':'){

						mvaddch(shot4.y, shot4.x, ' '); 
						mvaddch(shot4.y+1, shot4.x, ' '); 
						mvaddch(shot4.y-1, shot4.x, ' ');
						mvaddch(shot4.y, shot4.x+1, ' ');
						mvaddch(shot4.y, shot4.x-1, ' ');
						mvaddch(shot4.y+1, shot4.x+1, ' '); 
						mvaddch(shot4.y+1, shot4.x-1, ' ');
						mvaddch(shot4.y-1, shot4.x+1, ' '); 
						mvaddch(shot4.y-1, shot4.x-1, ' ');
						kill(shot4.pid, 1);
					}

					mvaddch(al[c].y, al[c].x, ' ');
					mvaddch(al[c].y, al[c].x+1, ' ');
					mvaddch(al[c].y, al[c].x+2, ' ');
					mvaddch(al[c].y, al[c].x+3, ' ');
					mvaddch(al[c].y, al[c].x+4, ' ');
					mvaddch(al[c].y, al[c].x+5, ' ');
					mvaddch(al[c].y, al[c].x+6, ' ');
					mvaddch(al[c].y, al[c].x+7, ' ');

					mvaddch(al[c].y+1, al[c].x+2, ' ');
					mvaddch(al[c].y+1, al[c].x+3, ' ');
					mvaddch(al[c].y+1, al[c].x+4, ' ');
					mvaddch(al[c].y+1, al[c].x+5, ' ');
					mvaddch(al[c].y+1, al[c].x+6, ' ');
					mvaddch(al[c].y+1, al[c].x+7, ' ');

					mvaddch(al[c].y-1, al[c].x+2, ' ');
					mvaddch(al[c].y-1, al[c].x+3, ' ');
					mvaddch(al[c].y-1, al[c].x+4, ' ');
					mvaddch(al[c].y-1, al[c].x+5, ' ');
					mvaddch(al[c].y-1, al[c].x+6, ' ');
					mvaddch(al[c].y-1, al[c].x+7, ' ');

					al[c].y=50;
					kill(al[c].pid, 1);

				}
			}
		}
		
		/**Controllo collisioni alieni livello 2 con i missili del giocatore
		 * Quando i missili si scontrano con un alieno, esplodono e ne chiudiamo il processo
		 * Quando una nave aliena viene colpita, ne chiudiamo il processo
		 * */
		if(valore_letto.sprite == ',' || valore_letto.sprite == '.' || valore_letto.sprite == ';' || valore_letto.sprite == ':'){

			for(c = MINALIENI2; c <= MAXALIENI2;c++){

				if(al[c-MINALIENI2].y==50){

					if((valore_letto.x==al2[c-MINALIENI2].x&&valore_letto.y==al2[c-MINALIENI2].y+1)||
						(valore_letto.x==al2[c-MINALIENI2].x+1&&valore_letto.y==al2[c-MINALIENI2].y+1)||
						(valore_letto.x==al2[c-MINALIENI2].x+2&&valore_letto.y==al2[c-MINALIENI2].y+1)||
						(valore_letto.x==al2[c-MINALIENI2].x+3&&valore_letto.y==al2[c-MINALIENI2].y+1)||
						(valore_letto.x==al2[c-MINALIENI2].x+4&&valore_letto.y==al2[c-MINALIENI2].y+1)||
						(valore_letto.x==al2[c-MINALIENI2].x+5&&valore_letto.y==al2[c-MINALIENI2].y+1)||
						(valore_letto.x==al2[c-MINALIENI2].x+6&&valore_letto.y==al2[c-MINALIENI2].y+1)||
						(valore_letto.x==al2[c-MINALIENI2].x+7&&valore_letto.y==al2[c-MINALIENI2].y+1)||
						(valore_letto.x==al2[c-MINALIENI2].x+8&&valore_letto.y==al2[c-MINALIENI2].y+1)||
						(valore_letto.x==al2[c-MINALIENI2].x&&valore_letto.y==al2[c-MINALIENI2].y-1)||
						(valore_letto.x==al2[c-MINALIENI2].x+1&&valore_letto.y==al2[c-MINALIENI2].y-1)||
						(valore_letto.x==al2[c-MINALIENI2].x+2&&valore_letto.y==al2[c-MINALIENI2].y-1)||
						(valore_letto.x==al2[c-MINALIENI2].x+3&&valore_letto.y==al2[c-MINALIENI2].y-1)||
						(valore_letto.x==al2[c-MINALIENI2].x+4&&valore_letto.y==al2[c-MINALIENI2].y-1)||
						(valore_letto.x==al2[c-MINALIENI2].x+5&&valore_letto.y==al2[c-MINALIENI2].y-1)||
						(valore_letto.x==al2[c-MINALIENI2].x+6&&valore_letto.y==al2[c-MINALIENI2].y-1)||
						(valore_letto.x==al2[c-MINALIENI2].x+7&&valore_letto.y==al2[c-MINALIENI2].y-1)||
						(valore_letto.x==al2[c-MINALIENI2].x+8&&valore_letto.y==al2[c-MINALIENI2].y-1)){

						if(valore_letto.sprite==','){

							mvaddch(shot1.y, shot1.x, ' '); 
							mvaddch(shot1.y+1, shot1.x, ' '); 
							mvaddch(shot1.y-1, shot1.x, ' ');
							mvaddch(shot1.y, shot1.x+1, ' ');
							mvaddch(shot1.y, shot1.x-1, ' ');
							mvaddch(shot1.y+1, shot1.x+1, ' '); 
							mvaddch(shot1.y+1, shot1.x-1, ' ');
							mvaddch(shot1.y-1, shot1.x+1, ' '); 
							mvaddch(shot1.y-1, shot1.x-1, ' ');
							kill(shot1.pid, 1);

						}

						if(valore_letto.sprite=='.'){

							mvaddch(shot2.y, shot2.x, ' '); 
							mvaddch(shot2.y+1, shot2.x, ' '); 
							mvaddch(shot2.y-1, shot2.x, ' ');
							mvaddch(shot2.y, shot2.x+1, ' ');
							mvaddch(shot2.y, shot2.x-1, ' ');
							mvaddch(shot2.y+1, shot2.x+1, ' '); 
							mvaddch(shot2.y+1, shot2.x-1, ' ');
							mvaddch(shot2.y-1, shot2.x+1, ' '); 
							mvaddch(shot2.y-1, shot2.x-1, ' ');
							kill(shot2.pid, 1);

						}

						if(valore_letto.sprite==';'){

							mvaddch(shot3.y, shot3.x, ' '); 
							mvaddch(shot3.y+1, shot3.x, ' '); 
							mvaddch(shot3.y-1, shot3.x, ' ');
							mvaddch(shot3.y, shot3.x+1, ' ');
							mvaddch(shot3.y, shot3.x-1, ' ');
							mvaddch(shot3.y+1, shot3.x+1, ' '); 
							mvaddch(shot3.y+1, shot3.x-1, ' ');
							mvaddch(shot3.y-1, shot3.x+1, ' '); 
							mvaddch(shot3.y-1, shot3.x-1, ' ');
							kill(shot3.pid, 1);

						}

						if(valore_letto.sprite==':'){

							mvaddch(shot4.y, shot4.x, ' '); 
							mvaddch(shot4.y+1, shot4.x, ' '); 
							mvaddch(shot4.y-1, shot4.x, ' ');
							mvaddch(shot4.y, shot4.x+1, ' ');
							mvaddch(shot4.y, shot4.x-1, ' ');
							mvaddch(shot4.y+1, shot4.x+1, ' '); 
							mvaddch(shot4.y+1, shot4.x-1, ' ');
							mvaddch(shot4.y-1, shot4.x+1, ' '); 
							mvaddch(shot4.y-1, shot4.x-1, ' '); 
							kill(shot4.pid, 1);

						}

						if(colpi_alieno[c-MINALIENI2]<=0){

							mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x, ' ');
							mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+1, ' ');
							mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+2, ' ');
							mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+3, ' ');
							mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+4, ' ');
							mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+5, ' ');
							mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+6, ' ');
							mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+7, ' ');
							mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+8, ' ');

							mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x, ' ');
							mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+1, ' ');
							mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+2, ' ');
							mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+3, ' ');
							mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+4, ' ');
							mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+5, ' ');
							mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+6, ' ');
							mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+7, ' ');
							mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+8, ' ');

							al2[c-MINALIENI2].y=50;
							kill(al2[c-MINALIENI2].pid, 1);

						} else {

							colpi_alieno[c-MINALIENI2]--;
						}
					}
				}
			}
		}

		switch(valore_letto.sprite){

			case '-':

				//Cancello la vecchia posizione della nave
				if(nav.x>=0){  
			        	mvaddch(nav.y, nav.x-1, ' ');
					mvaddch(nav.y, nav.x-2, ' ');
					mvaddch(nav.y, nav.x-3, ' ');
					mvaddch(nav.y, nav.x-4, ' ');
					mvaddch(nav.y, nav.x+1, ' ');
					mvaddch(nav.y, nav.x, ' ');
	
					mvaddch(nav.y+1, nav.x-1, ' ');
					mvaddch(nav.y+1, nav.x-2, ' ');
					mvaddch(nav.y+1, nav.x-3, ' ');
					mvaddch(nav.y+1, nav.x-4, ' ');
					mvaddch(nav.y+1, nav.x, ' ');

					mvaddch(nav.y+2, nav.x-1, ' ');
					mvaddch(nav.y+2, nav.x-2, ' ');
					mvaddch(nav.y+2, nav.x-3, ' ');
					mvaddch(nav.y+2, nav.x-4, ' ');
					mvaddch(nav.y+2, nav.x, ' ');
				
					mvaddch(nav.y-1, nav.x-1, ' ');
					mvaddch(nav.y-1, nav.x-2, ' ');
					mvaddch(nav.y-1, nav.x-3, ' ');
					mvaddch(nav.y-1, nav.x-4, ' ');
					mvaddch(nav.y-1, nav.x, ' '); 

					mvaddch(nav.y-2, nav.x-1, ' ');
					mvaddch(nav.y-2, nav.x-2, ' ');
					mvaddch(nav.y-2, nav.x-3, ' ');
					mvaddch(nav.y-2, nav.x-4, ' ');
					mvaddch(nav.y-2, nav.x, ' ');  
	        	}

				nav=valore_letto;

				break;

			case ',':

				//Cancello la vecchia posizione del colpo 1
				if(shot1.x>=0){ 

	                	mvaddch(shot1.y, shot1.x, ' ');

				}

				shot1=valore_letto;
				break;

			case '.':

				//Cancello la vecchia posizione del colpo 2
				if(shot2.x>=0){ 

					mvaddch(shot2.y, shot2.x, ' ');
	            }

				shot2=valore_letto;
				break;

			case ';':
				//Cancello la vecchia posizione del colpo 1
				if(shot3.x>=0){ 
	                		mvaddch(shot3.y, shot3.x, ' ');
				}
				shot3=valore_letto;
				break;

			case ':':

				//Cancello la vecchia posizione del colpo 2
				if(shot4.x>=0){ 

					mvaddch(shot4.y, shot4.x, ' ');
	            }

				shot4=valore_letto;

			case '+':
				bomba=valore_letto;
				    
		}

	//Stampa navi aliene livello 2
	for(c=MINALIENI2;c<=MAXALIENI2;c++){

		if(al[c-MINALIENI2].y==50){

			if(valore_letto.sprite>=c&&valore_letto.sprite<=c){

				//Cancello la vecchia posizione dell'alieno
				if(al2[c-MINALIENI2].x>=0){ 

				mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x, ' ');
				mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+1, ' ');
				mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+2, ' ');
				mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+3, ' ');
				mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+4, ' ');
				mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+5, ' ');
				mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+6, ' ');
				mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+7, ' ');
				mvaddch(al2[c-MINALIENI2].y+1, al2[c-MINALIENI2].x+8, ' ');

				mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x, ' ');
				mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+1, ' ');
				mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+2, ' ');
				mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+3, ' ');
				mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+4, ' ');
				mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+5, ' ');
				mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+6, ' ');
				mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+7, ' ');
				mvaddch(al2[c-MINALIENI2].y-1, al2[c-MINALIENI2].x+8, ' ');
				
				}

			al2[c-MINALIENI2]=valore_letto;

			}
		}
	}
	
	//Stampa navi aliene livello 1
	for(c=MINALIENI;c<=MAXALIENI;c++){

		if(valore_letto.sprite>=c&&valore_letto.sprite<=c){

			//Cancello la vecchia posizione dell'alieno
			if(al[c-MINALIENI].x>=0){  

				mvaddch(al[c-MINALIENI].y, al[c-MINALIENI].x, ' ');
				mvaddch(al[c-MINALIENI].y, al[c-MINALIENI].x+1, ' ');
				mvaddch(al[c-MINALIENI].y, al[c-MINALIENI].x+2, ' ');
				mvaddch(al[c-MINALIENI].y, al[c-MINALIENI].x+3, ' ');
				mvaddch(al[c-MINALIENI].y, al[c-MINALIENI].x+4, ' ');
				mvaddch(al[c-MINALIENI].y, al[c-MINALIENI].x+5, ' ');

				mvaddch(al[c-MINALIENI].y+1, al[c-MINALIENI].x+2, ' ');
				mvaddch(al[c-MINALIENI].y+1, al[c-MINALIENI].x+3, ' ');
				mvaddch(al[c-MINALIENI].y+1, al[c-MINALIENI].x+4, ' ');
				mvaddch(al[c-MINALIENI].y+1, al[c-MINALIENI].x+5, ' ');

				mvaddch(al[c-MINALIENI].y-1, al[c-MINALIENI].x+2, ' ');
				mvaddch(al[c-MINALIENI].y-1, al[c-MINALIENI].x+3, ' ');
				mvaddch(al[c-MINALIENI].y-1, al[c-MINALIENI].x+4, ' ');
				mvaddch(al[c-MINALIENI].y-1, al[c-MINALIENI].x+5, ' ');
			}

		mvaddch(valore_letto.y, valore_letto.x, valore_letto.sprite);
		al[c-MINALIENI]=valore_letto;

		}
	}

	//Controllo collisioni navi aliene di livello 1 con la nave del giocatore
	for(c=MINALIENI;c<=MAXALIENI;c++){

		if(valore_letto.sprite>=c&&valore_letto.sprite<=c){

			if((valore_letto.x+2==nav.x-1&&valore_letto.y+1==nav.y+2)||
				(valore_letto.x+3==nav.x-1&&valore_letto.y+1==nav.y+2)||
				(valore_letto.x+4==nav.x-1&&valore_letto.y+1==nav.y+2)||
				(valore_letto.x+5==nav.x-1&&valore_letto.y+1==nav.y+2)||
				(valore_letto.x+6==nav.x-1&&valore_letto.y+1==nav.y+2)||
				
				(valore_letto.x+2==nav.x-1&&valore_letto.y+1==nav.y-2)||
				(valore_letto.x+3==nav.x-1&&valore_letto.y+1==nav.y-2)||
				(valore_letto.x+4==nav.x-1&&valore_letto.y+1==nav.y-2)||
				(valore_letto.x+5==nav.x-1&&valore_letto.y+1==nav.y-2)||
				(valore_letto.x+6==nav.x-1&&valore_letto.y+1==nav.y+2)||

				(valore_letto.x+2==nav.x-1&&valore_letto.y-1==nav.y+2)||
				(valore_letto.x+3==nav.x-1&&valore_letto.y-1==nav.y+2)||
				(valore_letto.x+4==nav.x-1&&valore_letto.y-1==nav.y+2)||
				(valore_letto.x+5==nav.x-1&&valore_letto.y-1==nav.y+2)||
				(valore_letto.x+6==nav.x-1&&valore_letto.y-1==nav.y+2)||
				
				(valore_letto.x+2==nav.x-1&&valore_letto.y-1==nav.y-2)||
				(valore_letto.x+3==nav.x-1&&valore_letto.y-1==nav.y-2)||
				(valore_letto.x+4==nav.x-1&&valore_letto.y-1==nav.y-2)||
				(valore_letto.x+5==nav.x-1&&valore_letto.y-1==nav.y-2)||
				(valore_letto.x+6==nav.x-1&&valore_letto.y-1==nav.y+2)||

				(valore_letto.x==nav.x&&valore_letto.y==nav.y)||	
				(valore_letto.x==nav.x&&valore_letto.y==nav.y+2)||
				(valore_letto.x==nav.x&&valore_letto.y==nav.y-2)||
				(valore_letto.x==nav.x&&valore_letto.y==nav.y+1)||
				(valore_letto.x==nav.x&&valore_letto.y==nav.y-1)||
				(valore_letto.x==nav.x-1&&valore_letto.y==nav.y+2)||
				(valore_letto.x==nav.x-1&&valore_letto.y==nav.y-2)||
				(valore_letto.x==nav.x-1&&valore_letto.y==nav.y+1)||
				(valore_letto.x==nav.x-1&&valore_letto.y==nav.y-1)||			

				(valore_letto.x==nav.x&&valore_letto.y==nav.y)||
				(valore_letto.x==nav.x&&valore_letto.y==nav.y)){

				vite=0;
			}
		}
	}

	//Controllo collisioni navi aliene di livello 2 con la nave del giocatore
	for(c=MINALIENI2;c<=MAXALIENI2;c++){

		if(valore_letto.sprite>=c&&valore_letto.sprite<=c){

			if((valore_letto.x+2==nav.x-1&&valore_letto.y+1==nav.y+2)||
				(valore_letto.x+3==nav.x-1&&valore_letto.y+1==nav.y+2)||
				(valore_letto.x+4==nav.x-1&&valore_letto.y+1==nav.y+2)||
				(valore_letto.x+5==nav.x-1&&valore_letto.y+1==nav.y+2)||
				(valore_letto.x+6==nav.x-1&&valore_letto.y+1==nav.y+2)||
				
				(valore_letto.x+2==nav.x-1&&valore_letto.y+1==nav.y-2)||
				(valore_letto.x+3==nav.x-1&&valore_letto.y+1==nav.y-2)||
				(valore_letto.x+4==nav.x-1&&valore_letto.y+1==nav.y-2)||
				(valore_letto.x+5==nav.x-1&&valore_letto.y+1==nav.y-2)||
				(valore_letto.x+6==nav.x-1&&valore_letto.y+1==nav.y+2)||

				(valore_letto.x+2==nav.x-1&&valore_letto.y-1==nav.y+2)||
				(valore_letto.x+3==nav.x-1&&valore_letto.y-1==nav.y+2)||
				(valore_letto.x+4==nav.x-1&&valore_letto.y-1==nav.y+2)||
				(valore_letto.x+5==nav.x-1&&valore_letto.y-1==nav.y+2)||
				(valore_letto.x+6==nav.x-1&&valore_letto.y-1==nav.y+2)||
				
				(valore_letto.x+2==nav.x-1&&valore_letto.y-1==nav.y-2)||
				(valore_letto.x+3==nav.x-1&&valore_letto.y-1==nav.y-2)||
				(valore_letto.x+4==nav.x-1&&valore_letto.y-1==nav.y-2)||
				(valore_letto.x+5==nav.x-1&&valore_letto.y-1==nav.y-2)||
				(valore_letto.x+6==nav.x-1&&valore_letto.y-1==nav.y+2)||

				(valore_letto.x==nav.x&&valore_letto.y==nav.y)||	
				(valore_letto.x==nav.x&&valore_letto.y==nav.y+2)||
				(valore_letto.x==nav.x&&valore_letto.y==nav.y-2)||
				(valore_letto.x==nav.x&&valore_letto.y==nav.y+1)||
				(valore_letto.x==nav.x&&valore_letto.y==nav.y-1)||
				(valore_letto.x==nav.x-1&&valore_letto.y==nav.y+2)||
				(valore_letto.x==nav.x-1&&valore_letto.y==nav.y-2)||
				(valore_letto.x==nav.x-1&&valore_letto.y==nav.y+1)||
				(valore_letto.x==nav.x-1&&valore_letto.y==nav.y-1)||			

				(valore_letto.x==nav.x&&valore_letto.y==nav.y)||
				(valore_letto.x==nav.x&&valore_letto.y==nav.y)){

				vite=0;
			}
		}
	}
	
	//Controllo collisioni navi giocatore con le navi aliene
	if(valore_letto.sprite=='-'){

		for(c=MINALIENI;c<=MAXALIENI;c++){

			if((valore_letto.x==al[c-MINALIENI].x&&valore_letto.y==al[c-MINALIENI].y-2)||
				(valore_letto.x-1==al[c-MINALIENI].x&&valore_letto.y==al[c-MINALIENI].y-2)||
				(valore_letto.x-2==al[c-MINALIENI].x&&valore_letto.y==al[c-MINALIENI].y-2)||
				(valore_letto.x-3==al[c-MINALIENI].x&&valore_letto.y==al[c-MINALIENI].y-2)||
				(valore_letto.x-4==al[c-MINALIENI].x&&valore_letto.y==al[c-MINALIENI].y-2)||

				(valore_letto.x==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y-1)||
				(valore_letto.x-1==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y-1)||
				(valore_letto.x-2==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y-1)||
				(valore_letto.x-3==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y-1)||
				(valore_letto.x-4==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y-1)||
				
				(valore_letto.x==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y+1)||
				(valore_letto.x-1==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y+1)||
				(valore_letto.x-2==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y+1)||
				(valore_letto.x-3==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y+1)||
				(valore_letto.x-4==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y+1)||

				(valore_letto.x==al[c-MINALIENI].x&&valore_letto.y-2==al[c-MINALIENI].y-1)||
				(valore_letto.x-1==al[c-MINALIENI].x&&valore_letto.y-2==al[c-MINALIENI].y-1)||
				(valore_letto.x-2==al[c-MINALIENI].x&&valore_letto.y-2==al[c-MINALIENI].y-1)||
				(valore_letto.x-3==al[c-MINALIENI].x&&valore_letto.y-2==al[c-MINALIENI].y-1)||
				(valore_letto.x-4==al[c-MINALIENI].x&&valore_letto.y-2==al[c-MINALIENI].y-1)||
				
				(valore_letto.x==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y+1)||
				(valore_letto.x-1==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y+1)||
				(valore_letto.x-2==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y+1)||
				(valore_letto.x-3==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y+1)||
				(valore_letto.x-4==al[c-MINALIENI].x&&valore_letto.y+2==al[c-MINALIENI].y+1)||				

				(valore_letto.x==al[c-MINALIENI].x&&valore_letto.y==al[c-MINALIENI].y+2)||
				(valore_letto.x-1==al[c-MINALIENI].x&&valore_letto.y-2==al[c-MINALIENI].y+2)||
				(valore_letto.x-2==al[c-MINALIENI].x&&valore_letto.y-2==al[c-MINALIENI].y+2)||
				(valore_letto.x-3==al[c-MINALIENI].x&&valore_letto.y-2==al[c-MINALIENI].y+2)||
				(valore_letto.x-4==al[c-MINALIENI].x&&valore_letto.y-2==al[c-MINALIENI].y+2)||
				(valore_letto.x-1==al[c-MINALIENI].x&&valore_letto.y-2==al[c-MINALIENI].y-1)||
				(valore_letto.x-1==al[c-MINALIENI].x&&valore_letto.y-2==al[c-MINALIENI].y+1)||
				(valore_letto.x==al[c-MINALIENI].x&&valore_letto.y==al[c-MINALIENI].y)){

				vite=0;
			}
		}
	}

	//Controllo collisioni navi giocatore con le bombe aliene
	if(valore_letto.sprite=='+'){

		if(valore_letto.x==nav.x&&valore_letto.y==nav.y){

			vite=0;
		}
		if(valore_letto.x==nav.x-1&&valore_letto.y==nav.y){

			vite=0;
		}
		if(valore_letto.x==nav.x-2&&valore_letto.y==nav.y){

			vite=0;
		}
		if(valore_letto.x==nav.x-3&&valore_letto.y==nav.y){

			vite=0;
		}
		if(valore_letto.x==nav.x-4&&valore_letto.y==nav.y){

			vite=0;
		}
		if(valore_letto.x==nav.x+1&&valore_letto.y==nav.y){

			vite=0;
		}

		//parte superiore della nave
		if(valore_letto.x==nav.x-1&&valore_letto.y+1==nav.y){

			vite=0;
		}
		if(valore_letto.x==nav.x&&valore_letto.y+2==nav.y){

			vite=0;
		}
		if(valore_letto.x==nav.x-1&&valore_letto.y+2==nav.y){

			vite=0;
		}
		if(valore_letto.x==nav.x-2&&valore_letto.y+2==nav.y){

			vite=0;
		}
		if(valore_letto.x==nav.x-3&&valore_letto.y+2==nav.y){

			vite=0;
		}

		//parte inferiore della nave
		if(valore_letto.x==nav.x-1&&valore_letto.y-1==nav.y){

			vite=0;
		}
		if(valore_letto.x==nav.x&&valore_letto.y-2==nav.y){

			vite=0;
		}
		if(valore_letto.x==nav.x-1&&valore_letto.y-2==nav.y){

			vite=0;
		}
		if(valore_letto.x==nav.x-2&&valore_letto.y-2==nav.y){

			vite=0;
		}
		if(valore_letto.x==nav.x-3&&valore_letto.y-2==nav.y){

			vite=0;
		}
	
	}

	//Controllo navi distrutte
	navi_distrutte=0;

	for(c=0;c<26;c++){

		if(al[c].y==50){

			navi_distrutte++;

		}

		if(al2[c].y==50){

			navi_distrutte++;
		}
	}

	//Quando tutte le navi aliene vengono distrutte, finisce il gioco e si vince
	if(navi_distrutte==(MAXALIENI-MINALIENI+1)*2){
		vittoria=1;
		vite=0;
	}

	//Se il valore è la nave ci stampo sopra lo sprite
	if(valore_letto.sprite=='-') {
		sprintf(buffer, "[]]]]>");	
		mvaddstr(nav.y,nav.x-4, buffer);
	}
	
	if(valore_letto.sprite=='-') {
		sprintf(buffer, "| |");	
		mvaddstr(nav.y+1,nav.x-3, buffer);
	}
	
	if(valore_letto.sprite=='-') {
		sprintf(buffer, "===>");	
		mvaddstr(nav.y+2,nav.x-3, buffer);
	}

	if(valore_letto.sprite=='-') {
		sprintf(buffer, "| |");	
		mvaddstr(nav.y-1,nav.x-3, buffer);
	}
	
	if(valore_letto.sprite=='-') {
		sprintf(buffer, "===>");	
		mvaddstr(nav.y-2,nav.x-3, buffer);
	}


	//Se il valore è una bomba lo sostituisco con lo sprite o
	if(valore_letto.sprite=='+') {
		sprintf(buffer, "o ");	
		mvaddstr(bomba.y,bomba.x, buffer);
	}

	//Se il valore è uno sparo stampo *
	if(valore_letto.sprite=='.') {
		sprintf(buffer, "-");	
		mvaddstr(shot2.y,shot2.x, buffer);
	}

	if(valore_letto.sprite==',') {
		sprintf(buffer, "-");	
		mvaddstr(shot1.y,shot1.x, buffer);
	}

	if(valore_letto.sprite==';') {
		sprintf(buffer, "-");	
		mvaddstr(shot3.y,shot3.x, buffer);
	}

	if(valore_letto.sprite==':') {
		sprintf(buffer, "-");	
		mvaddstr(shot4.y,shot4.x, buffer);
	}

	//Applico sprite navi aliene di livello 2
	for(c=0;c<26;c++){
		if(valore_letto.sprite == al2[c].sprite){
			sprintf(buffer, "<[]");	
			mvaddstr(al2[c].y+1,al2[c].x, buffer);
		}
		
		if(valore_letto.sprite == al2[c].sprite){
			sprintf(buffer, "<[]");	
			mvaddstr(al2[c].y-1,al2[c].x, buffer);
		}

		if(valore_letto.sprite == al2[c].sprite){
			sprintf(buffer, "<[]");	
			mvaddstr(al2[c].y+1,al2[c].x+5, buffer);
		}
		
		if(valore_letto.sprite == al2[c].sprite){
			sprintf(buffer, "<[]");	
			mvaddstr(al2[c].y-1,al2[c].x+5, buffer);
		}
	}

	//Applico sprite navi aliene di livello 1
	for(c=0;c<26;c++){
		if(valore_letto.sprite == al[c].sprite){
			sprintf(buffer, "<|===|");	
			mvaddstr(al[c].y,al[c].x, buffer);
		}

		if(valore_letto.sprite == al[c].sprite){
			sprintf(buffer, "  \\==/");	
			mvaddstr(al[c].y+1,al[c].x, buffer);
		}

		if(valore_letto.sprite == al[c].sprite){
			sprintf(buffer, "  /==\\");	
			mvaddstr(al[c].y-1,al[c].x, buffer);
		}
	}

	//Se una nave nemica arriva al lato sinistro dello schermo il giocatore perde		
	if(valore_letto.sprite>=MINALIENI&&valore_letto.sprite<=MAXALIENI&&valore_letto.x<=1){
		vite=0;
	}
		
	if(valore_letto.sprite>=MINALIENI2&&valore_letto.sprite<=MAXALIENI2&&valore_letto.x<=1){
		vite=0;
	}
	
	//Stampa informazioni a schermo
	sprintf(buffer, "Vite: %d | Premi 0 per arrenderti", vite);	
	mvaddstr(1, 1, buffer);

	//Stampa navi distrutte ovvero il punteggio
	sprintf(buffer, "Punti: %d ", navi_distrutte);	
	mvaddstr(1, 40, buffer);

	//stampa delimitazione area di gioco
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

	
	//Stampa fine area di gioco superiore
	sprintf(buffer, "________________________________________________________________________________");
	mvaddstr(2, 1, buffer);
	mvaddstr(2, 40, buffer);


	refresh();
	
	//chiudi il gioco se il giocatore preme 0
	if(valore_letto.sprite=='0'){
		vite=0;
	}

	}while(vite>0); 

	//ritorna il risultato del gioco (1 vittoria, 0 sconfitta)
	return vittoria;
};
