#include <stdio.h>
#include <stdlib.h>

#include "Node.h"

void node_dump(Node_t* node)
{
    if (!node) return;
    printf(OP_OUT " ", *((int*)node->data));
    node_dump(node->next);
}

void node_dtor(Node_t* node)
{
    if (!node) return;
    free(node->data);
    node_dtor(node->next);
    free(node->next);
}
