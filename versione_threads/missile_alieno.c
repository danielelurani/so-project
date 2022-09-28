/*missile delle navi aliene */

#include "librerie.h"

void *sparo_alieno(void *arg){
	
	//c prende il valore passato alla funzione alieno per identificare l'alieno da cui parte la bomba
	int c=*(int *)arg;
	bomba[c].x = al[c].x-1;
	bomba[c].y = al[c].y;

	// Buffer per stampare stringhe
	char buffer_b1[512];

	//spostamento del missile alieno
	while(bomba[c].x>-2&&bomba[c].y>0&&bomba[c].x<MAXX&&bomba[c].y<MAXY){

		pthread_mutex_lock(&mutex);

		bomba[c].x--;
		sprintf(buffer_b1, "o ");	
		mvaddstr(bomba[c].y,bomba[c].x, buffer_b1);

		pthread_mutex_unlock(&mutex);
		
		usleep(43000);
	}
};


