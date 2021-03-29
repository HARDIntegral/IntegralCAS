#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "../includes/symbols.h"
#include "../includes/binary.h"
#include "../includes/stack.h"

typedef struct token token;
struct token {
    char* part;
    token* next;
};

token* addToken(char *str) {
    token* new = (token*)malloc(sizeof(token));
    new->part = str;
    new->next = NULL;
    return new;
}

token* tokenize(char* input) {
    token* head = NULL;
    token* tok = NULL;
    char* str_token = strtok(input, "\{} ");
    while (str_token != NULL) {
        tok = addToken(str_token);
        if (head == NULL)
            head = tok;
        else {
            token* tmp = head;
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = tok;
        }
        str_token = strtok(NULL, "\{} ");
    }
    return head;
}

void printTokens(token* head) {
    token* tmp = head;
    while (tmp != NULL) {
        printf("Token - %s\n", tmp->part);
        tmp = tmp->next;
    }
}