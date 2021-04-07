#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "../includes/list.h"

void addToken(node_l** token_head, const char* token) {
    appendListNode(token_head, &token, CHAR);
}

node_l* tokenize(char* input) {
    node_l* token_head = NULL;
    char* str_token = strtok(input, "\{} ");
    while (str_token != NULL) {
        addToken(&token_head, str_token);
        str_token = strtok(NULL, "\{} ");
    }
    return token_head;
}

void* returnToken(node_l* current_node) {
    return returnValue(current_node);
}

void clearTokens(node_l** token_head) {
    destroyList(token_head);
}

void printTokens(node_l** token_head) {
    printList(token_head);
}