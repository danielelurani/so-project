/* Navi aliene di livello 1 */

#include "alieni.h"

void *alieno(void *arg){

	int cooldown = 0; 	//Variabile per il cooldown della bomba

	// Buffer per stampare stringhe
	char buffer[512];

	//c prende il valore passato nel pthread_create
	int c=*(int *)arg;
	/* Ottiene dimensioni dello sprite */
	int dimsprite = sizeof(sprite1); 
	
	int spostamentox; 	//Spostamento orizzontale
	int spostamentoy=-1; 	//Spostamento verticale

	int primox=al[c].x;
	int direzione=-1; 

	while(al[c].vite>0){

		//Se gli alieni si muovono verso sinistra 2 volte smettono di farlo e tornano a muoversi verticalmente
		if(al[c].x<=primox-2){
			spostamentox=0; 
			primox=al[c].x; 
			if(direzione==1){spostamentoy=+1;}
			if(direzione==-1){spostamentoy=-1;}
		}

		/* Se supero l'area Y schermo inizo il movimento a destra e inverto la direzione y */
		if (al[c].y + spostamentoy < 2 || al[c].y + spostamentoy > MAXY-2){
			spostamentoy=0;
			spostamentox=-10;
			direzione=-direzione;
		}
		
		//Cancellamento vecchia posizione dell'alieno
		if(al[c].x>=0){  

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
		}

		//Aggiornamento posizione alieno
		pthread_mutex_lock(&mutex);

		al[c].x=al[c].x+spostamentox;
		al[c].y=al[c].y+spostamentoy;

		pthread_mutex_unlock(&mutex);

		//Stampa sprite dell'alieno, se di livello 1 ->-{ e se di livello 2 ++++
		if(al[c].vite==3){

			pthread_mutex_lock(&mutex);
			sprintf(buffer, "<|===|");	
			mvaddstr(al[c].y,al[c].x, buffer);
			pthread_mutex_unlock(&mutex);

			pthread_mutex_lock(&mutex);
			sprintf(buffer, "  \\==/");	
			mvaddstr(al[c].y+1,al[c].x, buffer);
			pthread_mutex_unlock(&mutex);

			pthread_mutex_lock(&mutex);
			sprintf(buffer, "  /==\\");	
			mvaddstr(al[c].y-1,al[c].x, buffer);
			pthread_mutex_unlock(&mutex);
		}
		
		if(al[c].vite<=2){
			pthread_mutex_lock(&mutex);
			sprintf(buffer, "<[]");	
			mvaddstr(al[c].y+1,al[c].x, buffer);
			pthread_mutex_unlock(&mutex);

			pthread_mutex_lock(&mutex);
			sprintf(buffer, "<[]");	
			mvaddstr(al[c].y-1,al[c].x, buffer);
			pthread_mutex_unlock(&mutex);

			pthread_mutex_lock(&mutex);
			sprintf(buffer, "<[]");	
			mvaddstr(al[c].y+1,al[c].x+5, buffer);
			pthread_mutex_unlock(&mutex);

			pthread_mutex_lock(&mutex);
			sprintf(buffer, "<[]");	
			mvaddstr(al[c].y-1,al[c].x+5, buffer);
			pthread_mutex_unlock(&mutex);

			
		}

		//Inserisco una pausa per rallentare il movimento
		usleep(260000);
		if(al[c].x<0)al[c].vite=0;

		cooldown++;
		if(cooldown == 20){

			cooldown = 0;
			pthread_create(&bomba[c].thread, NULL, sparo_alieno, arg);

		}

	}

	pthread_join(bomba[c].thread, NULL);
};
