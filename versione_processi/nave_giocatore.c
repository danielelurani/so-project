/* Funzioni nave giocatore */

#include "nave_giocatore.h"

int colpo=0;

void nave_giocatore(int pipeout){

	/* Ottiene dimensioni dello sprite */
	int dimsprite = sizeof(sprite1);  

	//Pid processo figlio sparo e processo padre nave
	int pid_sparo1;
	int pid_sparo2;
	int pid_nave=getpid();
	
	//Variabili per il cooldown dello sparo
	long time_dif;
	struct timeval t1;
	struct timeval t2;
	t1=t2;
	
	//inizializzo oggetto nave
	struct oggetto nav;

	//inizializzo dati oggetto nave
	nav.x=7-(dimsprite/2); 
	nav.y=MAXY/2;
	nav.sprite='-';
	nav.vite=0;
	
	clear();
	write(pipeout, &nav, sizeof(nav));

	//loop di esistenza della nave del giocatore
	while(true) {

		int c=getch();

		switch(c){

			case '0':
				nav.sprite='0';
				break;

			case KEY_UP:
				if(nav.y>5) nav.y-=1;
				break;

			case KEY_DOWN:
				if(nav.y<MAXY-3) nav.y+=1;
				break;	

			case ' ':

				gettimeofday(&t2, NULL);
				time_dif = timevaldiff(&t1, &t2);

				//Cooldown tra un colpo e l'altro
				if(time_dif >= 2000){

					//variabile per determinare se lo sparo è pari o dispari
					if(colpo==0){

						colpo=1;

					} else {

						if(colpo==1){

							colpo=0;
						}
					}

					t1 = t2;

					/* In base alla scelta precedente, si genera lo sparo corrispondente*/
					switch(colpo){

						case 0:

							pid_sparo1=fork(); //Generazione sparo 1

							switch(pid_sparo1){
								case -1:

									perror("Creazione processo non riusicta");
									break;

								case 0:

									sparo(pipeout, nav.y, 0, colpo);
									exit(0);
							}

							pid_sparo2=fork(); //Generazione sparo 2

							switch(pid_sparo2){
								case -1:

									perror("Creazione processo non riusicta");
									break;

								case 0:

									sparo(pipeout, nav.y, 1, colpo);
									exit(0);
							}

							break;

						case 1:
							pid_sparo1=fork(); //Generazione sparo 1

							switch(pid_sparo1){

								case -1:

									perror("Creazione processo non riusicta");
									break;

								case 0:

									sparo(pipeout, nav.y, 0, colpo);
									exit(0);
							}

							pid_sparo2=fork(); //Generazione sparo 2

							switch(pid_sparo2){
								case -1:

									perror("Creazione processo non riusicta");
									break;
								case 0:
								
									sparo(pipeout, nav.y, 1, colpo);
									exit(0);
							}

							break;
					}
				}
		}

		write(pipeout, &nav, sizeof(nav));
	}

	close(pipeout);
	exit(0);
};
