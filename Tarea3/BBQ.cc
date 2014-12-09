/*
 * BBQ.cc -- Blocking Bounded Queue.
 */
#include <assert.h>
#include <pthread.h>
#include "BBQ.h"

BBQ::BBQ()
{
  nFull = 0;
  firstFull = 0;
  nextEmpty = 0;
}

// Wait until there is room 
// then insert an item.
void
BBQ::insert(int item)
{
  lock.Acquire();
  
  while(isFull()){
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
int
BBQ::remove(void)
{
  int ret;
  lock.Acquire();
  
  while(isEmpty()){
    itemAdded.Wait(&lock);
  }
  assert(!isEmpty());
  ret = items[firstFull];
  nFull--;
  firstFull = (firstFull + 1) % MAX;

  itemRemoved.Signal(&lock);
  lock.Release();
  return ret;
}
