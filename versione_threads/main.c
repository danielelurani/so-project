/* Main del programma */

#include "librerie.h"

	/* Mutex per la gestione tra i thread*/
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(){

	vite=1;
	int sprite_alieni;			//carattere che viene assegnato ad ogni alieno per differenziarli
	int y=4;				//distanza iniziale tra gli alieni
	int c=0, C[MAXALIENI-MINALIENI];	//contatore per gli alieni

	//Inizializzazione navicella giocatore e navicelle aliene
	
    	nav.x=-1;

	for(c=0;c<MAXALIENI-MINALIENI;c++){

		al[c].x = -1;
	}
	

	pthread_t thread_nave_giocatore, thread_alieni;	

	/* Inizializza lo schermo e i colori*/
	initscr();

	start_color();

	//creazione coppia caratteri bianchi su sfondo nero
	init_pair(1,COLOR_WHITE,COLOR_BLACK);

	attron(COLOR_PAIR(1));

	/* Disabilita la visualizzazione dei tasti premuti */   
  	noecho();

	/* Abilita la gestione dei tasti freccia */
  	keypad(stdscr, 1);

	// Disattiva l'input stdin bufferizzato
	cbreak();
			
    srand((int)time(NULL));
  	curs_set(0);
  
	/* Creo il thread nave giocatore */
	pthread_create(&thread_nave_giocatore, NULL, nave_giocatore, NULL);
	
	c=0;

	//Generazione processi alieni
	for(sprite_alieni=MINALIENI;sprite_alieni<MAXALIENI;sprite_alieni++){
		
		//input alieno 76 (posizione in fondo allo schermo=
		//c contatore per posizione verticle
		//sprite_alieni carattere assegnato all'alieno

		al[c].x = 112;
		al[c].y = y;
		al[c].sprite = sprite_alieni;
		al[c].vite=3;
		C[c]=c;
		//Creo il thread per l'alieno c
		pthread_create(&thread_alieni, NULL, alieno, &C[c]);

		c++;
		y=y+7;
	}

	//La funzione main chiama la funzione di controllo
	controllo();

	for(c=0;c<MAXALIENI-MINALIENI;c++){
		pthread_join(al[c].thread, NULL);	
	}
	pthread_join(nav.thread, NULL);

 	//Elimino il mutex
 	pthread_mutex_destroy (&mutex);

   	endwin();

    return 0;
};
