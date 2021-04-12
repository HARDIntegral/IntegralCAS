#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#include "../parser/parser.h"

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("NEEDS ARGUMENT\n");
    return 0;
  } else if (argc > 2) {
    printf("TOO MANY ARGUMENTS\n");
    return 0;
  }
  parse(&argv[1]);
}
