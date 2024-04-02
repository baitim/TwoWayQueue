#ifndef NODE_H
#define NODE_H

#include "Config.h"

struct Node_t {
    void* data;
	struct Node_t *next;
    struct Node_t *prev;
};

void node_dump(Node_t* node);
void node_dtor(Node_t* node);

#endif // NODE_H