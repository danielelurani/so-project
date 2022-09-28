OUTPUT = SpaceDefender
SORGENTI = main.o controllo.o nave_giocatore.o missile_giocatore.o alieni.o missile_alieno.o
LIBRERIE = -lncurses -lpthread

SpaceDefender: $(SORGENTI)
	gcc -o $(OUTPUT) $(SORGENTI) $(LIBRERIE)
	
main.o: main.c librerie.h
	gcc -c -o main.o main.c $(CFLAGS)

controllo.o: controllo.c controllo.h librerie.h
	gcc -c -o controllo.o controllo.c $(CFLAGS)
	
nave_giocatore.o: nave_giocatore.c nave_giocatore.h librerie.h
	gcc -c -o nave_giocatore.o nave_giocatore.c $(CFLAGS)
	
missile_giocatore.o: missile_giocatore.c missile_giocatore.h librerie.h
	gcc -c -o missile_giocatore.o missile_giocatore.c $(CFLAGS)
	
alieni.o: alieni.c alieni.h librerie.h
	gcc -c -o alieni.o alieni.c $(CFLAGS)

missile_alieno.o: missile_alieno.c missile_alieno.h librerie.h
	gcc -c -o missile_alieno.o missile_alieno.c $(CFLAGS)
	
clean:
	rm *.o $(OUTPUT)
