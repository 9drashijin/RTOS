#ifndef __MAILBOX_H
#define __MAILBOX_H

#include <stdint.h>
#include "Mutex.h"
#include "Semaphore.h"

typedef struct {
	uint32_t		*buffer;
	uint32_t		size;
	Semaphore		slotsAvailable;
	Semaphore		slotsUsed;
	uint32_t		writeIndex;
	uint32_t		readIndex;
	Mutex			mutexForBuffer;
}Mailbox;

#endif /* __MAILBOX_H */
