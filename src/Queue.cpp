#include <stdlib.h>
#include <string.h>

#include "ANSI_colors.h"
#include "Queue.h"
#include "Node.h"

bool queue_ctor(Queue_t** queue)
{
    *queue = (Queue_t*) malloc(sizeof(Queue_t*));
    if (!(*queue)) 
        return true;
    (*queue)->first = nullptr;
    (*queue)->last  = nullptr;

    return false;
}

void queue_dump(Queue_t* queue)
{
    if (!queue) return;
    printf(print_lgreen("Queue:\n"));
    node_dump(queue->first);
    printf("\n");
}

void queue_dtor(Queue_t* queue)
{
    if (!queue) return;

    if (queue->first) {
        node_dtor(queue->first);
        free(queue->first);
    }

    free(queue);
}

bool push_front(Queue_t* queue, size_t elem_size, void* data)
{
    Node_t* new_node = (Node_t*) malloc(sizeof(Node_t));
    if (!new_node) 
        return true;
    new_node->data = (char*) malloc(elem_size);
    if (!new_node->data) 
        return true;

    memcpy(new_node->data, data, elem_size);

    new_node->prev = nullptr;

    if (queue->first) {
        new_node->next = queue->first;
        queue->first->prev = new_node;
        queue->first = new_node;
    } else {
        new_node->next = nullptr;
        queue->first = new_node;
        queue->last = new_node;
    }

    return false;
}

bool pop_front(Queue_t* queue, ELEM* elem)
{
    if (!queue->first) return true;

    Node_t* new_first = queue->first->next;

    if (queue->first->next)
        queue->first->next->prev = nullptr;

    *elem = *((ELEM*)queue->first->data);

    free(queue->first->data);
    queue->first->next = nullptr;
    queue->first->prev = nullptr;
    free(queue->first);

    queue->first = new_first;
    return false;
}

bool push_back(Queue_t* queue, size_t elem_size, void* data)
{
    Node_t* new_node = (Node_t*) malloc(sizeof(Node_t));
    if (!new_node)
        return true;
    new_node->data = (char*) malloc(elem_size);
    if (!new_node->data) 
        return true;

    memcpy(new_node->data, data, elem_size);

    new_node->next = nullptr;

    if (queue->last) {
    new_node->prev = queue->last;
    queue->last->next = new_node;
    queue->last = new_node;
    } else {
        new_node->prev = nullptr;
        queue->first = new_node;
        queue->last = new_node;
    }
    
    return false;
}

bool pop_back(Queue_t* queue, ELEM* elem)
{   
    if (!queue->last) return true;

    Node_t* new_last = queue->last->prev;

    if (queue->last->prev)
        queue->last->prev->next = nullptr;

    *elem = *((ELEM*)queue->last->data);

    free(queue->last->data);
    queue->last->next = nullptr;
    queue->last->prev = nullptr;
    free(queue->last);

    queue->last = new_last;
    return false;
}