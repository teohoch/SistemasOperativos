/*
 * BBQ.h -- Blocking Bounded Queue.
 */
#ifndef _BBQ_H_
#define _BBQ_H_
#include <pthread.h>
#include "Lock.h"
#include "Cond.h"
#include "Job.h"

const int MAX = 10;

class BBQ{
 private:
  // Synchronization variables
  Lock lock;
  Cond itemAdded;
  Cond itemRemoved;

  // State variables
  Job items[MAX];
  int nFull;
  int firstFull;
  int nextEmpty;
  int jobNumber;

 public: 
  BBQ();
  ~BBQ() {};
  void insert(Job item);
  Job remove();

 private:
  // Private methods are called with lock already held
  inline bool isFull() {return (nFull == MAX ? true : false);};
  inline bool isEmpty() {return (nFull == 0 ? true : false);};
};
#endif
