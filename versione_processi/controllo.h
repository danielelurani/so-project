/* Libreria contenente le funzioni di controllo */

#ifndef CONTROLLO_H
#define CONTROLLO_H

#include "librerie.h"

#define MAXX 120  	//Numero di colonne dello schermo
#define MAXY 36  	//Numero di righe dello schermo

//Sprite usato dalla navicella
static const char sprite1[5]={"<-|->"};

//Struttura che identifica gli oggetti a schermo
struct oggetto{
	char sprite;
	int x;
	int y;
	int pid;
	int vite;
};

int controllo(int pipein, int pipeout);
long timevaldiff(struct timeval *t1, struct timeval *t2);

#endif
