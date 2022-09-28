/* Funzioni nave giocatore */

#include "nave_giocatore.h"


void *nave_giocatore(void *arg){

	// Buffer per stampare lo sprite della nave
	char sprite_nave[6];

	int colpo=0;
	
	pthread_t tshot1, tshot2, tshot3, tshot4; //Threads per gestire i missili
	//Variabili per il cooldown dello sparo
	long time_dif;
	struct timeval t1;
	struct timeval t2;
	t1=t2;

	//inizializzo dati oggetto nave
	nav.x=5; 
	nav.y=MAXY/2;
	nav.sprite='-';
	
	clear();

	//loop di esistenza della nave del giocatore
	int vita = 1;
	while(vita==1) {

		sprintf(sprite_nave, "[]]]]>");	
		mvaddstr(nav.y,nav.x-4, sprite_nave);

		sprintf(sprite_nave, "| |");	
		mvaddstr(nav.y+1,nav.x-3, sprite_nave);

		sprintf(sprite_nave, "===>");	
		mvaddstr(nav.y+2,nav.x-3, sprite_nave);

		sprintf(sprite_nave, "| |");	
		mvaddstr(nav.y-1,nav.x-3, sprite_nave);

		sprintf(sprite_nave, "===>");	
		mvaddstr(nav.y-2,nav.x-3, sprite_nave);


		int c=getch();	//Prende il tasto premuto dalla tastiera

		switch(c){

			case '0':	
				nav.sprite='0';	//Trasforma il carattere identificatore della nave in 0 per indicare alla funzone controllo di terminare il gioco
				vite=0;
				break;

			case KEY_UP:
				pthread_mutex_lock(&mutex);
				//Cancella la vecchia posizione della nave
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
				mvaddch(nav.y-2, nav.x+1, ' '); 
				
				//Stampa la nave una posizione più in alto
				if(nav.y>3) nav.y-=1;
				pthread_mutex_unlock(&mutex);
				break;

			case KEY_DOWN:
				pthread_mutex_lock(&mutex);
				//Cancella la vecchia posizione della nave
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
				mvaddch(nav.y-2, nav.x+1, ' '); 				

				//Stampa la nave una posizione più in basso
				if(nav.y<MAXY-3) nav.y+=1;
				pthread_mutex_unlock(&mutex);
				break;	

			case ' ':

				pthread_mutex_lock(&mutex);
				mvaddch(nav.y-2, nav.x+1, ' ');
				pthread_mutex_unlock(&mutex);
				
				gettimeofday(&t2, NULL);
				time_dif = timevaldiff(&t1, &t2);
				//Cooldown tra un colpo e l'altro
				if(time_dif >= 1500){
					if(colpo==1){colpo=0;}else{colpo=1;}
					t1=t2;
					if(colpo==0){
						pthread_create(&tshot1, NULL, sparo1, NULL);
						pthread_create(&tshot2, NULL, sparo2, NULL);
					}
					if(colpo==1){
						pthread_create(&tshot3, NULL, sparo3, NULL);
						pthread_create(&tshot4, NULL, sparo4, NULL);
					}
				}
		}
	}
	
	pthread_join(tshot1, NULL);
	pthread_join(tshot2, NULL);
	pthread_join(tshot3, NULL);
	pthread_join(tshot4, NULL);
};
