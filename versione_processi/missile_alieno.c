/*missile delle navi aliene */

#include "librerie.h"

void sparo_alieno(int pipeout, int y, int direzione, int x){

	struct oggetto missile_alieno; //inizializzo il missile alieno

	//Inizializzo dati del missile alieno
	missile_alieno.y=y;
	missile_alieno.x=x;
	missile_alieno.sprite='+';
	missile_alieno.vite=0;

	//spostamento del missile alieno
	while(missile_alieno.x > -1 && missile_alieno.y > 2 && missile_alieno.x < MAXX && missile_alieno.y < MAXY){

			missile_alieno.pid=getpid();
			missile_alieno.x--;

			write(pipeout, &missile_alieno, sizeof(missile_alieno));

			usleep(90000);
	}
};
