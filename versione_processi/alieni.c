/* Navi aliene di livello 1 */

#include "alieni.h"

int colpo_alieno = 0;
int cooldown = 0;

void alieno(int pipeout, int x, int y, char sprite){
	/* Ottiene dimensioni dello sprite */
	int dimsprite = sizeof(sprite1); 

	//Pid processo figlio bomba e processo padre nave
	int pid_missile_alieno;
	int pid_alieno=getpid();
	
	int spostamentox; 	//Spostamento orizzontale
	int spostamentoy=-1; 	//Spostamento verticale

	int primox=x;
	int direzione=-1; 
	
	//Variabili per il cooldown della bomba
	long time_dif;
	struct timeval t1;
	struct timeval t2;
	t1=t2;

	//Impostazione valori di partenza dell'alieno
	struct oggetto al;
	al.x=x; 
	al.y=y;
	al.sprite=sprite;
	al.vite=2;
	al.pid=getpid();
	int vite;
	
	//write(pipeout, &al, sizeof(al));
	vite=1;
	while(vite==1){
		//Se gli alieni si muovono verso sinistra 2 volte smettono di farlo e tornano a muoversi verticalmente
		if(al.x<=primox-2){
			spostamentox=0; 
			primox=al.x; 
			if(direzione==1){spostamentoy=+1;}
			if(direzione==-1){spostamentoy=-1;}
		}

		/* Se supero l'area Y schermo inizo il movimento a destra e inverto la direzione y */
		if (al.y + spostamentoy < 4 || al.y + spostamentoy > MAXY-2){
			spostamentoy=0;
			spostamentox=-10;
			direzione=-direzione;
		}
		
		al.x=al.x+spostamentox;
		al.y=al.y+spostamentoy;

		/* Inserisco una pausa per rallentare il movimento */
		usleep(320000);
		if(al.x<0)vite=0;

		cooldown++;
		if(cooldown == 20){
			cooldown = 0;
			pid_missile_alieno=fork(); 
				switch(pid_missile_alieno){
					case -1:
						perror("Creazione processo non riusicta");
						break;
					case 0:
						sparo_alieno(pipeout, al.y, 0, al.x-1);
						exit(0);
				}
		}
		/* Comunico le coordinate correnti al processo padre */
		write(pipeout, &al, sizeof(al));
	}
	close(pipeout);
	exit(0);
};

