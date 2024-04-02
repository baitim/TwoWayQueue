#include <stdio.h>
#include <stdlib.h>

#include "ANSI_colors.h"
#include "Node.h"
#include "Queue.h"
#include "Config.h"

int main()
{
    printf(print_lblue("# Implementation of Queue.\n"
                       "# (c) Baidiusenov Timur, 2024\n\n"));

    Queue_t* queue = nullptr;
    bool err = queue_ctor(&queue);
    if (err) goto error;

    for (int i = 0; i < 5; i++) {
        err = push_front(queue, ELEM_SIZE, &i);
        if (err) goto error;
    }

    queue_dump(queue);

    for (int i = 0; i < 10; i++) {
        err = push_back(queue, ELEM_SIZE, &i);
        if (err) goto error;
    }

    queue_dump(queue);

    for (int i = 0; i < 8; i++) {
        err = pop_front(queue);
        if (err) goto error;
    }

    queue_dump(queue);

    for (int i = 0; i < 4; i++) {
        err = pop_back(queue);
        if (err) goto error;
    }

    queue_dump(queue);

    for (int i = 0; i < 5; i++) {
        err = push_front(queue, ELEM_SIZE, &i);
        if (err) goto error;
    }

    queue_dump(queue);

    for (int i = 0; i < 10; i++) {
        err = push_back(queue, ELEM_SIZE, &i);
        if (err) goto error;
    }

    queue_dump(queue);

    goto finally;

error:
    fprintf(stderr, print_lred("something go wrong :()\n"));

finally:
    queue_dtor(queue);
    printf(print_lblue("Bye! ") print_lred("<3\n"));

    return 0;
}