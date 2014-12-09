CC			=	g++
CFLAGS		=  -c -Wall

all: tarea3 mop

tarea3:  BBQMain.cc sthread.c bbq.o Cond.o Lock.o 
	$(CC) -Wall -D_POSIX_PTHREAD_SEMANTICS BBQMain.cc sthread.c BBQ.o Cond.o Lock.o -lpthread -lrt -o Tarea3
	
bbq.o: BBQ.cc BBQ.h Lock.h Cond.h
	$(CC) $(CFLAGS) BBQ.cc Lock.h Cond.h
	
cond.o:  Cond.cc Cond.h Lock.h
	$(CC) $(CFLAGS) Cond.cc Lock.h -o cond.o
	
lock.o: Lock.cc Lock.h
	$(CC) $(CFLAGS) Lock.cc -o lock.o

clean:
	rm -rf *.o *.out Tarea3
mop:
	rm -rf *.o *.h.gch
