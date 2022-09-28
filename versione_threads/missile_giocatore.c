/* Funzione missile del giocatore */

#include "missile_giocatore.h"

void *sparo1(void *args){

	//char bufferShot1[128];

	int cicli = 0;	//variabile per determinare il movimento verticale dello sparo

	shot1.y=nav.y; //posizione di partenza del missile
	shot1.x=7;

	while(shot1.x<MAXX&&shot1.y<MAXY){

		pthread_mutex_lock(&mutex);
		mvaddch(shot1.y,shot1.x, ' ');	//Cancello la vecchia posizione del missile
		pthread_mutex_unlock(&mutex);		
		
		//Muovo il missile per 5 colonne , poi 1 riga in verticale
		if(cicli == 5){
			pthread_mutex_lock(&mutex);
			shot1.x++;
			shot1.y--;
			pthread_mutex_unlock(&mutex);
			cicli = 0;

		} else {
			pthread_mutex_lock(&mutex);
			shot1.x++;

			pthread_mutex_unlock(&mutex);
			cicli++;
		}

			pthread_mutex_lock(&mutex);
			mvaddch(shot1.y,shot1.x, '-');
			pthread_mutex_unlock(&mutex);
					
			usleep(25000);
	}
};

void *sparo2(void *args){

	int cicli = 0;	//variabile per determinare il movimento verticale dello sparo

	shot2.y=nav.y;	//posizione di partenza del missile
	shot2.x=7;
	
	while(shot2.x<MAXX&&shot2.y<MAXY){
		pthread_mutex_lock(&mutex);
		mvaddch(shot2.y,shot2.x, ' ');	//Cancello la vecchia posizione del missile
		pthread_mutex_unlock(&mutex);

		//Muovo il missile per 5 colonne , poi 1 riga in verticale
		if(cicli == 5){
			pthread_mutex_lock(&mutex);
			shot2.x++;
			shot2.y++;
			pthread_mutex_unlock(&mutex);
			cicli = 0;

		} else {
			pthread_mutex_lock(&mutex);
			shot2.x++;

			pthread_mutex_unlock(&mutex);
			cicli++;
		}

			pthread_mutex_lock(&mutex);
			mvaddch(shot2.y,shot2.x, '-');
			pthread_mutex_unlock(&mutex);
					
			usleep(25000);
	}
};

void *sparo3(void *args){

	int cicli = 0;	//variabile per determinare il movimento verticale dello sparo
	
	shot3.y=nav.y;	//posizione di partenza del missile
	shot3.x=7;
	
	while(shot3.x<MAXX&&shot3.y<MAXY){
		pthread_mutex_lock(&mutex);
		mvaddch(shot3.y,shot3.x, ' ');	//Cancello la vecchia posizione del missile
		pthread_mutex_unlock(&mutex);
		//Muovo il missile per 5 colonne , poi 1 riga in verticale
		if(cicli == 5){
			pthread_mutex_lock(&mutex);
			shot3.x++;
			shot3.y--;
			pthread_mutex_unlock(&mutex);
			cicli = 0;

		} else {
			pthread_mutex_lock(&mutex);
			shot3.x++;

			pthread_mutex_unlock(&mutex);
			cicli++;
		}

			pthread_mutex_lock(&mutex);
			mvaddch(shot3.y,shot3.x, '-');
			pthread_mutex_unlock(&mutex);
					
			usleep(25000);
	}
};

void *sparo4(void *args){

	int cicli = 0;	//variabile per determinare il movimento verticale dello sparo

	shot4.y=nav.y;	//posizione di partenza del missile
	shot4.x=7;
	
	while(shot4.x<MAXX&&shot4.y<MAXY){
		pthread_mutex_lock(&mutex);
		mvaddch(shot4.y,shot4.x, ' ');	//Cancello la vecchia posizione del missile
		pthread_mutex_unlock(&mutex);
		//Muovo il missile per 5 colonne , poi 1 riga in verticale
		if(cicli == 5){
			pthread_mutex_lock(&mutex);
			shot4.x++;
			shot4.y++;
			pthread_mutex_unlock(&mutex);
			cicli = 0;

		} else {
			pthread_mutex_lock(&mutex);
			shot4.x++;

			pthread_mutex_unlock(&mutex);
			cicli++;
		}

			pthread_mutex_lock(&mutex);
			mvaddch(shot4.y,shot4.x, '-');
			pthread_mutex_unlock(&mutex);
					
			usleep(25000);
	}
};
