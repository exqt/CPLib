#include "polynomial.hpp"

void testPolynomial() {
  {
    Polynomial<int> A(1), B(1);
    A[0] = 1; A[1] = 2;
    B[0] = 2; B[1] = 3;

    // 6x^2+7x+2
    assert((A*B).eval(2) == 24+14+2);

    // 5x+3
    assert((A+B).eval(2) == 13);
  }
}