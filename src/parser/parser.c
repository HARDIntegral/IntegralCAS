#include <math.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "../includes/binary.h"
#include "../includes/list.h"
#include "../includes/list_helpers.h"
#include "../includes/symbols.h"
#include "parse_list.h"
#include "tokenizer.h"

#define TRUE 1
#define FALSE 0

jmp_buf savebuf;
int exception_value = 0;
#define TRY if ((exception_value = setjmp(savebuf)) == 0)
#define CATCH(NUM) else if (exception_value == NUM)
#define CATCHALL else
#define THROW(NUM) longjmp(savebuf, NUM)
#define NOTANUMBEREXCEPTION 1

int parseInteger(char *input);
parse_list *postLexicalCleanup(LIST *token_list, int *integer_capacity,
                               OPERATOR *oper_capacity, TYPE *types);

void parse(char *input) {
  // Lexical Analysis
  LIST *token_list = tokenize(input);
  iterate(token_list, printString, FALSE);
  printf("\n");

  // Prepare Shunting-Yard
  int *integer_capacity = (int *)malloc((token_list->size) * sizeof(int));
  OPERATOR *oper_capacity =
      (OPERATOR *)malloc((token_list->size) * sizeof(OPERATOR));
  TYPE *types = (TYPE *)malloc((token_list->size) * sizeof(TYPE));
  parse_list *token_intermediate =
      postLexicalCleanup(token_list, integer_capacity, oper_capacity, types);
  printParseList(token_intermediate);
  printf("\n");

  // Shunting-Yard
  // TODO: finally get to parsing

  // Clean up memory
  if (destroyList(token_list) == FAILURE)
    printf("FAILURE DEALLOCATING LIST");
  if (destroyParseList(token_intermediate) == FAILURE)
    printf("FAILURE DEALLOCATING LIST");
  free(integer_capacity);
  free(oper_capacity);
  free(types);
  integer_capacity = NULL;
  oper_capacity = NULL;
  types = NULL;
}

int parseInteger(char *input) {
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

parse_list *postLexicalCleanup(LIST *token_list, int *integer_capacity,
                               OPERATOR *oper_capacity, TYPE *types) {
  int counter = 0;

  parse_list *token_intermediate = generateParseList();
  node_l *tmp_token = token_list->head;
  while (tmp_token != NULL) {
    void *data = tmp_token->data;
    TRY {
      integer_capacity[counter] = parseInteger((char *)data);
      types[counter] = INT;
      if (appendParseList(token_intermediate, &integer_capacity[counter],
                          &types[counter]) == FAILURE)
        printf("FAILURE APPENDING INTEGER");
    }
    CATCH(NOTANUMBEREXCEPTION) {
    if (strcmp((char *)data, "plus") == 0)
      oper_capacity[counter] = PLUS;
    if (strcmp((char *)data, "minus") == 0)
        oper_capacity[counter] = MINUS;
    if (strcmp((char *)data, "times") == 0)
        oper_capacity[counter] = MULT;
    if (strcmp((char *)data, "div") == 0)
        oper_capacity[counter] = DIV;
    if (strcmp((char *)data, "sin") == 0)
        oper_capacity[counter] = SIN;
    if (strcmp((char *)data, "cos") == 0)
        oper_capacity[counter] = COS;
    if (strcmp((char *)data, "tan") == 0)
        oper_capacity[counter] = TAN;
    if (strcmp((char *)data, "arcsin") == 0)
        oper_capacity[counter] = arcsin;
    if (strcmp((char *)data, "arccos") == 0)
        oper_capacity[counter] = arccos;
    if (strcmp((char *)data, "arctan") == 0)
        oper_capacity[counter] = arctan;
    if (strcmp((char *)data, "csc") == 0)
        oper_capacity[counter] = csc;
    if (strcmp((char *)data, "sec") == 0)
        oper_capacity[counter] = sec;
    if (strcmp((char *)data, "cot") == 0)
        oper_capacity[counter] = cot;
    if (strcmp((char *)data, "arccsc") == 0)
        oper_capacity[counter] = arccsc;
    if (strcmp((char *)data, "arcsec") == 0)
        oper_capacity[counter] = arcsec;
    if (strcmp((char *)data, "arccot") == 0)
        oper_capacity[counter] = arccot;
    if (strcmp((char *)data, "sinh") == 0)
        oper_capacity[counter] = SINH;
    if (strcmp((char *)data, "cosh") == 0)
        oper_capacity[counter] = COSH;
    if (strcmp((char *)data, "tanh") == 0)
        oper_capacity[counter] = TANH;
    if (strcmp((char *)data, "arsinh") == 0)
        oper_capacity[counter] = arsinh;
    if (strcmp((char *)data, "arcosh") == 0)
        oper_capacity[counter] = arcosh;
    if (strcmp((char *)data, "artanh") == 0)
        oper_capacity[counter] = artanh;
    if (strcmp((char *)data, "csch") == 0)
        oper_capacity[counter] = csch;
    if (strcmp((char *)data, "sech") == 0)
        oper_capacity[counter] = sech;
    if (strcmp((char *)data, "coth") == 0)
        oper_capacity[counter] = coth;
    if (strcmp((char *)data, "arcsch") == 0)
        oper_capacity[counter] = arcsch;
    if (strcmp((char *)data, "arsech") == 0)
        oper_capacity[counter] = arsech;
    if (strcmp((char *)data, "arcoth") == 0)
        oper_capacity[counter] = arcoth;
    if (strcmp((char *)data, "frac") == 0)
        oper_capacity[counter] = frac;
    if (strcmp((char *)data, "^") == 0)
        oper_capacity[counter] = POW;
    if (strcmp((char *)data, "root") == 0)
        oper_capacity[counter] = ROOT;
    if (strcmp((char *)data, "vpi") == 0)
        oper_capacity[counter] = vpi;
    if (strcmp((char *)data, "veul") == 0)
        oper_capacity[counter] = veul;
    types[counter] = OPER;
    if (appendParseList(token_intermediate, &oper_capacity[counter],
                        &types[counter]) == FAILURE)
      printf("FAILURE APPENDING OPERATOR");
    }
    CATCHALL { printf("FATAL ERROR\n"); }
    counter++;
    tmp_token = tmp_token->next;
  } 

  return token_intermediate;
}
