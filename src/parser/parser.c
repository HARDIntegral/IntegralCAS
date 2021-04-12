#include <math.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "../includes/binary.h"
#include "../includes/stack.h"
#include "../includes/symbols.h"
#include "tokenizer.h"

jmp_buf savebuf;
int exception_value = 0;
#define TRY if ((exception_value = setjmp(savebuf)) == 0)
#define CATCH(NUM) else if (exception_value == NUM)
#define CATCHALL else
#define THROW(NUM) longjmp(savebuf, NUM)
#define NOTANUMBEREXCEPTION 1

int parseInteger(char *input);

void parse(char *input) {
  node_l *token_list = tokenize(input);
  printTokens(&token_list);
  node_l *tmp_token = token_list;

  // Shunting-Yard
  node_l *token_intermediate = NULL;
  int integer_test = 0;
  while (tmp_token != NULL) {
    TRY {
      integer_test = parseInteger((char *)(returnToken(tmp_token)));
      appendListNode(&token_intermediate, &integer_test, INT);
    }
    CATCH(NOTANUMBEREXCEPTION) {
      OPERATOR OPER = PLUS;
      OPERATOR tmpOPER = OPER;
      appendListNode(&token_intermediate, &tmpOPER, SYMBOL);
    }
    CATCHALL { printf("FATAL ERROR\n"); }
    tmp_token = getNextNode(tmp_token);
  }
  printList(&token_intermediate);
  printf("Len token_list - %d\n", getLength(&token_list));
  printf("Len token_intermediate - %d\n", getLength(&token_intermediate));
  clearTokens(&token_list);
  destroyList(&token_intermediate);
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
