#ifndef TOKEN_H
#define TOKEN_H

typedef struct token token;
struct token {
    char* part;
    token* next;
};

token* tokenize(char* input);
void printTokens(token* head);

#endif // !TOKEN_H
