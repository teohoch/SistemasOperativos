#include <assert.h>
#include <stdio.h>
#include <stdlib.h> 
#include <sstream>
#include <iostream>
#include <sys/types.h>
#include "sthread.h"
#include "BBQ.h"
#include <typeinfo>


void *putSome(void *tsqueuePtr)
{
	int ii = 0;
	BBQ *queue = (BBQ *)tsqueuePtr;
	
	unsigned long int tid = pthread_self();
	while(true)
	{
		ii = rand() % 11;
		Job work;
		work.setId(tid);
		work.setValue(ii);
		queue->insert(work);		
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



int main(int argc, char *argv[])
{
    if (argc >= 3)
    {
		remove( "log.txt" );
        std::istringstream iss1( argv[1] );
        std::istringstream iss2( argv[2] );
        int val1, val2;

        if (iss1 >> val1)
        {
            if (iss2 >> val2)
			{
				BBQ *queue;
				sthread_t producers[val1];
				sthread_t consumers[val2];

				int ii;

				queue = new BBQ();

				// Start the worker threads
				for(ii = 0; ii < val1; ii++){    
					sthread_create_p(&producers[ii], putSome, queue);
				}


				// Remove from the queue

				//printf("Queue %d:\n", 0);
				for(ii = 0; ii < val2; ii++)
				{ 
					sthread_create_p(&consumers[ii], getSome, queue);
				}

				while(true);
			}
        }
    }

    return 0;
}



