#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <string>
#include <math.h> 
#include <cmath>
#include <stdlib.h> 
#include < stdlib.h >
#include <map>

enum Trigono { SIN = 1, COS, TAN, ASIN, ACOS, ATAN, BACK, EMPTY };
enum Hyperbolic { SINH = 1, COSH, TANH, ASINH, ACOSH, ATANH, EXIT, NICHTS };
enum Power { POW = 1, POWTHIRD, POWN, SQRT, CBRT, SQRTN, HYPOT, RETURN, VACANT };
enum ErrorGamma { ERF = 1, ERFC, TGAMMA, LGAMMA, FALLBACK, CLEAR };
enum Standard { DEG = 1, RAD, GRAD };

/*std::map<Standard, std::string> StandardToString = {{DEG, "DEGREE"},
                                     { RAD, "RADS" },
                                     { GRAD, "GRADS" } };*/

class Calculator
{
private:
    Trigono trigono;
    Hyperbolic hyperbolic;
    Power power;
    ErrorGamma errorgama;
    Standard myStandard;

public:
    Calculator();
    ~Calculator() {}
    bool Menu();
    void BasicMathematicalOperators();
    void TrigonometricOperators();
    void HyperbolicOperators();
    void PowerFunctions();
    void ErrorGammaFunctions();
    void DegRadGrad();
  /*  std::string enumToString(Standard standard)
    {
        return StandardToString[standard];
    }*/
};
#endif
