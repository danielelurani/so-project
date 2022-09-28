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

#include "controllo.h"
#include "nave_giocatore.h"
#include "missile_giocatore.h"
#include "alieni.h"
#include "missile_alieno.h"

//La quantità di alieni generata è la differenza tra MAXALIENI e MINALIENI +1 (dafault 70-65 e 102-97)
//Le navi aliene di secondo livello devono essere la stessa quantità di quelle di primo
	
#define MAXALIENI 69		//valore corrispettivo della tabella ascii da assegnare all'ultimo alieno di livello 1
#define MINALIENI 65		//valore corrispettivo della tabella ascii da assegnare al primo alieno di livello 1
#define MAXALIENI2 101		//valore corrispettivo della tabella ascii da assegnare all'ultimo alieno di livello 2
#define MINALIENI2 97		//valore corrispettivo della tabella ascii da assegnare al primo alieno di livello 2

#endif
