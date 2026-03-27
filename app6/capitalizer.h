#ifndef CAPITALIZER_H
#define CAPITALIZER_H

#include "common.h"

void capitalizer(char *buf, sem_t sem_produced, sem_t sem_capitalized);

#endif
