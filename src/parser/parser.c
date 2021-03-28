#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>

#include "symbols.h"
#include "binary.h"
#include "stack.h"

// Just for testing the N-ary Tree
void parse(char** input) {
    OPERATOR a = PLUS;
    int b = 5342;
    int c = 54543;
    int d = 423;
    int e = 422;
    int f = 89;

    node_s* head = NULL;
    push(&head, NULL, &a);
    push(&head, &b, NULL);
    push(&head, &c, NULL);
    push(&head, &d, NULL);
    push(&head, &e, NULL);
    push(&head, &f, NULL);
    
    printStack(&head);

    node_s* A = pop(&head);
    node_s* B = pop(&head);
    destroy(&A);
    destroy(&B);

    printStack(&head);
}
