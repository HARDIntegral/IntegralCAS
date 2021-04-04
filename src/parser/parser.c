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
    token* tmp_token = token_list;

    // Shunting-Yard
    node_pl* token_itermediate = NULL;
    int integer_test = 0;
    //printTokens(tmp_token);
    while (tmp_token != NULL) {
        TRY {
            integer_test = parseInteger(tmp_token->part);
            addToParseList(&token_itermediate, &integer_test, NULL);
        } CATCH(NOTANUMBEREXCEPTION){
            OPERATOR OPER = PLUS;
            if (strcmp(tmp_token->part, "minus") == 0) 
                OPER = MINUS;
            else if (strcmp(tmp_token->part, "times") == 0)
                OPER = MULT;
            else if (strcmp(tmp_token->part, "div") == 0)
                OPER = DIV;
            else if (strcmp(tmp_token->part, "sin") == 0)
                OPER = SIN;
            else if (strcmp(tmp_token->part, "cos") == 0)
                OPER = COS;
            else if (strcmp(tmp_token->part, "tan") == 0)
                OPER = TAN;
            else if (strcmp(tmp_token->part, "arcsin") == 0)
                OPER = arcsin;
            else if (strcmp(tmp_token->part, "arccos") == 0)
                OPER = arccos;
            else if (strcmp(tmp_token->part, "arctan") == 0)
                OPER = arctan;
            else if (strcmp(tmp_token->part, "csc") == 0)
                OPER = csc;
            else if (strcmp(tmp_token->part, "sec") == 0)
                OPER = sec;
            else if (strcmp(tmp_token->part, "cot") == 0)
                OPER = cot;
            else if (strcmp(tmp_token->part, "arccsc") == 0)
                OPER = arccsc;
            else if (strcmp(tmp_token->part, "arcsec") == 0)
                OPER = arcsec;
            else if (strcmp(tmp_token->part, "arccot") == 0)
                OPER = COS;
            else if (strcmp(tmp_token->part, "sinh") == 0)
                OPER = SINH;
            else if (strcmp(tmp_token->part, "cosh") == 0)
                OPER = COSH;
            else if (strcmp(tmp_token->part, "tanh") == 0)
                OPER = TANH;
            else if (strcmp(tmp_token->part, "arsinh") == 0)
                OPER = arsinh;
            else if (strcmp(tmp_token->part, "arcosh") == 0)
                OPER = arcosh;
            else if (strcmp(tmp_token->part, "artanh") == 0)
                OPER = artanh;
            else if (strcmp(tmp_token->part, "csch") == 0)
                OPER = csch;
            else if (strcmp(tmp_token->part, "sech") == 0)
                OPER = sech;
            else if (strcmp(tmp_token->part, "coth") == 0)
                OPER = coth;
            else if (strcmp(tmp_token->part, "arcsch") == 0)
                OPER = arcsch;
            else if (strcmp(tmp_token->part, "arsech") == 0)
                OPER = arsech;
            else if (strcmp(tmp_token->part, "arcoth") == 0)
                OPER = arcoth;
            else if (strcmp(tmp_token->part, "frac") == 0)
                OPER = frac;
            else if (strcmp(tmp_token->part, "^") == 0)
                OPER = POW;
            else if (strcmp(tmp_token->part, "root") == 0)
                OPER = ROOT;
            else if (strcmp(tmp_token->part, "vpi") == 0)
                OPER = vpi;
            else if (strcmp(tmp_token->part, "veul") == 0)
                OPER = veul;
            OPERATOR tmpOPER = OPER;
            addToParseList(&token_itermediate, NULL, &tmpOPER);
        } CATCHALL {
            printf("FATAL ERROR\n");
        }
        tmp_token = tmp_token->next;
    }
    printParseList(token_itermediate);
    clearTokens(&tmp_token);
    destroyParseList(&token_itermediate);
}

int parseInteger(char* input) {
    int result = 0;
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] > 57 || input[i] < 48) {
            THROW(NOTANUMBEREXCEPTION);
        }
        result = result + (input[i] - 48) * (int)ceil(pow(10, len - i - 1));
    }
    return result;
}
