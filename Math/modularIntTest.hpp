#include <cassert>
#include "modularInt.hpp"

void testModularInt() {
  const int MOD = 1000000007;
  using mint = modularInt<MOD>;

  mint A, B, C, D;

  A = 3, B = 42;
  assert(A+B == 45);
  assert(A*B == 126);
  assert(A-B == MOD-42+3);
  C = A/B;
  assert(C*B == A);

  A = 123456789, B = 987654321;
  assert(A*B == 123456789LL * 987654321LL % MOD);

  A = 3, B = 5, C = 2, D = 3;
  assert(C.inv()*C == 1);
  assert((A/B+C/D)*15 == 19);

  assert(A*B*C/D == 5*2);
  assert(A-B+C*D == 3-5+2*3);

  mint E1 = mint(1)/mint(2);
  mint E2 = mint(1)/mint(3);
  mint E = E1 - E2;
  assert(E * 6 == 1);

  mint R;
  for(int i=1; i<=10000; i++) R -= i;
  assert(R == (MOD - 10000*10001/2));

  R = 1;
  mint R2 = 1;
  for(int i=1; i<=100; i++) R /= i;
  for(int i=1; i<=100; i++) R2 *= i;
  assert(R*R2 == 1);
}

