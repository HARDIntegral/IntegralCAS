#include <stdio.h>
#include <stdlib.h>

void printString(void *input) {
  char *string = (char *)input;
  printf("%s ", string);
}

void printInteger(void *input) {
  int value = *(int *)input;
  printf("%d ", value);
}
