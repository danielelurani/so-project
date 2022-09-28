/* RACCOLTA LIBRERIE PER IL FUNZIONAMENTO DEL PROGRAMMA */

#ifndef LIBRERIE_H
#define LIBRERIE_H

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <malloc.h>
#include <semaphore.h>

#include "controllo.h"
#include "nave_giocatore.h"
#include "missile_giocatore.h"
#include "alieni.h"
#include "missile_alieno.h"

//La quantità di alieni generata è la differenza tra MAXALIENI e MINALIENI
	
#define MAXALIENI 70		//valore corrispettivo della tabella ascii da assegnare all'ultimo alieno di livello 1
#define MINALIENI 65		//valore corrispettivo della tabella ascii da assegnare al primo alieno di livello 1

//Struttura che identifica gli oggetti a schermo
struct oggetto{
	char sprite;
	int x;
	int y;
	int direzione;
	pthread_t thread;
	int vite;
};

#define MAXX 120  	//Numero di colonne dello schermo
#define MAXY 36  	//Numero di righe dello schermo

//Sprite usato dalla navicella
static const char sprite1[6]={"}=|]>"};

/* Mutex per la gestione tra i thread*/
extern pthread_mutex_t mutex;

int vite;

/* Inizializzo ogni oggetto del gioco */
struct oggetto nav, valore_letto, bomba[MAXALIENI-MINALIENI], bomba2[MAXALIENI-MINALIENI], shot1, shot2, shot3, shot4, al[MAXALIENI-MINALIENI];


#endif
