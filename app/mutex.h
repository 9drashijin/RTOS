#ifndef __MUTEX_H
#define __MUTEX_H

#include <stdint.h>
#include "Task.h"
#include "LinkedList.h"

typedef struct {
	Tcb     		*owner;
	uint32_t		counter;
	LinkedList		blockedTcb;
}Mutex;

void initMutex(Mutex *mutex);
void acquireMutex(Mutex *mutex);
void releaseMutex(Mutex *mutex);

#endif /* __MUTEX_H */
