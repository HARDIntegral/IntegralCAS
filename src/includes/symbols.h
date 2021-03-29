#ifndef SYMBOL_H
#define SYMBOL_H

typedef enum oper OPERATOR;
enum oper {
    //operations
    PLUS,           // \plus
    MINUS,          // \minus
    times,          // \times
    DIV,            // \div
    //circular
    SIN,            // \sin
    COS,            // \cos
    TAN,            // \tan
    arcsin,         // \arcsin
    arccos,         // \arcccos
    arctan,         // \arctan
    csc,            // \csc 
    sec,            // \sec
    cot,            // \cot
    arccsc,         // \arccsc 
    arcsec,         // \arcsec
    arccot,         // \arccot
    //hyperbolic
    SINH,           // \sinh
    COSH,           // \cosh
    TANH,           // \tanh
    arsinh,         // \operatorname{arsinh}
    arcosh,         // \operatorname{arcosh}
    artanh,         // \operatorname{artanh}
    csch,           // \operatorname{csch}
    sech,           // \operatorname{sech}
    coth,           // \coth
    arcsch,         // \operatorname{arcsch}
    arsech,         // \operatorname{arsech}
    arcoth,         // \operatorname{arcoth}
    //other
    frac,           // \frac{}{}
    POW,            // \^{}
    SQRT,           // \sqrt[]{}
    //constanst
    vpi,            // \vpi
    eul             // \eul
};

#endif // !SYMBOL_H