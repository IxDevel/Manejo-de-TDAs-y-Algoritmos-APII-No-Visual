CC=g++
CFLAGS=-Wall -g
target: clear main

clear:
	cls
	del *.o *.exe *.h.gch

main: main.cpp DependenciasComunes.o ListasSimples.o ListasDoblementeEnlazadas.o ListasCirculares.o Pilas.o Colas.o Multilista.o AlgoritmosDeOrdenamientoEnteros.o  AlgoritmosDeOrdenamientoStrings.o 
	$(CC) $(CFLAGS) DependenciasComunes.o ListasSimples.o ListasDoblementeEnlazadas.o ListasCirculares.o Pilas.o Colas.o Multilista.o AlgoritmosDeOrdenamientoEnteros.o AlgoritmosDeOrdenamientoStrings.o  main.cpp -o main

DependenciasComunes.o: DependenciasComunes.cpp DependenciasComunes.h
	$(CC) $(CFLAGS) -c DependenciasComunes.cpp

ListasSimples.o: DependenciasComunes.o 
	$(CC) $(CFLAGS) -c DependenciasComunes.o ListasSimples.cpp 

ListasDoblementeEnlazadas.o: DependenciasComunes.o 
	$(CC) $(CFLAGS) -c DependenciasComunes.o ListasDoblementeEnlazadas.cpp 

ListasCirculares.o: DependenciasComunes.o 
	$(CC) $(CFLAGS) -c DependenciasComunes.o ListasCirculares.cpp 

Pilas.o: DependenciasComunes.o
	$(CC) $(CFLAGS) -c DependenciasComunes.o Pilas.cpp 

Colas.o: DependenciasComunes.o 
	$(CC) $(CFLAGS) -c DependenciasComunes.o Colas.cpp 

Multilista.o: DependenciasComunes.o 
	$(CC) $(CFLAGS) -c DependenciasComunes.o Multilista.cpp 

AlgoritmosDeOrdenamientoEnteros.o: DependenciasComunes.o 
	$(CC) $(CFLAGS) -c DependenciasComunes.o AlgoritmosDeOrdenamientoEnteros.cpp

AlgoritmosDeOrdenamientoStrings.o: DependenciasComunes.o 
	$(CC) $(CFLAGS) -c DependenciasComunes.o AlgoritmosDeOrdenamientoStrings.cpp

