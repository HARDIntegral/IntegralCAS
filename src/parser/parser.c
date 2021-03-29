#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <setjmp.h>
#include <string.h>

#include "../includes/symbols.h"
#include "../includes/binary.h"
#include "../includes/stack.h"
#include "parse_list.h"
#include "tokenizer.h"

jmp_buf savebuf;
int exception_value = 0;
#define TRY if ((exception_value = setjmp(savebuf)) == 0)
#define CATCH(NUM) else if (exception_value == NUM)
#define CATCHALL else
#define THROW(NUM) longjmp(savebuf, NUM)
#define NOTANUMBEREXCEPTION 1

int parseInteger(char* input);

void parse(char** input) {
    token* token_list = tokenize(*input);
    token* tmp = token_list;

    // Shunting-Yard
    node_pl* token_itermediate = NULL;
    int integer_test = 0;
    while (tmp != NULL) {
        TRY {
            integer_test = parseInteger(tmp->part);
            printf("TEST 0\n");
            addToParseList(&token_itermediate, &integer_test, NULL);
        } CATCH(NOTANUMBEREXCEPTION) {
            OPERATOR PLACEHOLDER = PLUS;
            printf("TEST 1\n");
            addToParseList(&token_itermediate, NULL, &PLACEHOLDER);
        } CATCHALL {
            printf("FATAL ERROR\n");
        }
        tmp = tmp->next;
    }
    printf("TEST 2\n");
    printParseList(token_itermediate);
}

int parseInteger(char* input) {
    int result = 0;
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] > 57 || input[i] < 48) {
            THROW(NOTANUMBEREXCEPTION);
        }
        result = result + (input[i] - 48) * (int)ceil(pow(10, len - i- 1));
    }
    return result;
}
