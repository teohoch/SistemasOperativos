#include <assert.h>
#include <stdio.h>
#include <stdlib.h> 

#include <iostream>
#include "sthread.h"
#include "BBQ.h"


void *putSome(void *tsqueuePtr)
{
	int ii = 0;
	BBQ *queue = (BBQ *)tsqueuePtr;
	while(true)
	{
		ii = rand() % 11;
		queue->insert(ii);		
	} 
  
  return NULL;
}  

void *getSome(void *tsqueuePtr)
{
	BBQ *queue = (BBQ *)tsqueuePtr;
	
	while(true)
	{
		Job Valores = queue->remove();		
	} 
  
  return NULL;
} 


int main(int argc, char **argv)
{
  BBQ *queue;
  sthread_t producers[3];
  sthread_t consumers[3];
  
  int ii;
  
  queue = new BBQ();

  // Start the worker threads
  for(ii = 0; ii < 3; ii++){    
    sthread_create_p(&producers[ii], putSome, queue);
  }
  

  // Remove from the queue
  
    printf("Queue %d:\n", 0);
    for(ii = 0; ii < 3; ii++)
    { 
		sthread_create_p(&consumers[ii], getSome, queue);
	}
	
	while(true);
  
}
