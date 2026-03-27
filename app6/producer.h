#ifndef PRODUCER_H
#define PRODUCER_H

#include "common.h"

void producer(char *buf, sem_t sem_empty, sem_t sem_produced);

#endif
