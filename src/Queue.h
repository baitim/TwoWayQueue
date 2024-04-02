#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

#include "Config.h"

struct Queue_t {
	struct Node_t *first;
    struct Node_t *last;
};

bool queue_ctor (Queue_t** queue);
void queue_dump (Queue_t* queue);
void queue_dtor (Queue_t* queue);
bool push_front (Queue_t* queue, size_t elem_size, void* data);
bool pop_front  (Queue_t* queue, ELEM* elem);
bool push_back  (Queue_t* queue, size_t elem_size, void* data);
bool pop_back   (Queue_t* queue, ELEM* elem);

#endif // QUEUE_H