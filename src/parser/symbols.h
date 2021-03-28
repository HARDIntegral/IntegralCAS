#ifndef SYMBOL_H
#define SYMBOL_H

typedef enum oper OPERATOR;
enum oper {
    NONE,
    PLUS,
    MINUS,
    MULT,
    DIV,
    POW,
    ROOT,
    E,
    PI,
    SIN,
    COS,
    TAN,
    ARCSIN,
    ARCCOS,
    ARCTAN,
    FACT,
    MOD,
    ABS,
};

#endif // !SYMBOL_H