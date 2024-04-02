#include <stdio.h>
#include <stdlib.h>

#include "ANSI_colors.h"
#include "Node.h"

void node_dump(Node_t* node)
{
    if (!node) return;
    printf(print_lgreen(OP_OUT "\t"), *((ELEM*)node->data));
    node_dump(node->next);
}

void node_dtor(Node_t* node)
{
    if (!node) return;

    if (node->data)
        free(node->data);

    if (node->next) {
        node_dtor(node->next);
        free(node->next);
    }
}
