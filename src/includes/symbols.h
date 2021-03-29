#ifndef SYMBOL_H
#define SYMBOL_H

typedef enum oper OPERATOR;
enum oper {
    //operations
    PLUS,           // +
    MINUS,          // -
    times,          // \times
    DIV,            // \div
    //circular
    sin,            // \sin
    cos,            // \cos
    tan,            // \tan
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
    sinh,           // \sinh
    cosh,           // \cosh
    tanh,           // \tanh
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
    pow,            // ^{}
    sqrt            // \sqrt[]{}
};

#endif // !SYMBOL_H