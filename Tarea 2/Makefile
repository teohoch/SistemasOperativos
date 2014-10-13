CC		=	g++
CFLAGS		=  -c -Wall

all: tarea2 mop run

tarea2:  main.o 
	$(CC)   main.o  -o tarea2

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp
clean:
	rm -rf *.o tarea2
mop:
	rm -rf *.o
run:
	./tarea2
