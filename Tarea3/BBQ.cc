/*
 * BBQ.cc -- Blocking Bounded Queue.
 */
#include <assert.h>
#include <pthread.h>
#include <fstream>
#include <sys/types.h>
#include "BBQ.h"

BBQ::BBQ()
{
	nFull = 0;
	firstFull = 0;
	nextEmpty = 0;
	jobNumber = 0;
}

// Wait until there is room 
// then insert an item.
void BBQ::insert(int item)
{
	lock.Acquire();

	while(isFull())
	{
		itemRemoved.Wait(&lock);
	}
	assert(!isFull());
	items[nextEmpty] = item;
	nFull++;
	nextEmpty = (nextEmpty + 1) % MAX;

	itemAdded.Signal(&lock);
	lock.Release();
	return;
}

// Wait until there is an item 
// then remove an item.
Job BBQ::remove(void)
{
	int ret;
	lock.Acquire();
	  
	while(isEmpty())
	{
	  itemAdded.Wait(&lock);
	}
	assert(!isEmpty());
	ret = items[firstFull];
	nFull--;
	firstFull = (firstFull + 1) % MAX;
	
	
	std::ofstream outfile;
	outfile.open("test.txt", std::ios_base::app);
	outfile << "El procesador "<<pthread_self()<< " imprimio el job "<< jobNumber << " demorandose " << ret << " segundos \n"; 
	
	Job retorno;
	retorno.setValue(ret);
	retorno.setId(jobNumber);
	jobNumber++;

	itemRemoved.Signal(&lock);
	lock.Release();
	return retorno;
}
