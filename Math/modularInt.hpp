#include <iostream>

#ifndef _MOD_TYPE_
#define _MOD_TYPE_

// 1000000007
// 998244353 = 119 * 2^23 + 1 // primitive root = 3
// 1004535809 = 479 * (2^21) + 1 // primitive root = 3

template<unsigned int MOD>
struct modularInt {
  unsigned int n;

  modularInt() : n(0) {}
  modularInt(int n) : n((n%MOD+MOD)%MOD) {}
  modularInt(long long n) : n((n%MOD+MOD)%MOD) {}
  modularInt(unsigned int n) : n(n%MOD) {}
  modularInt& operator=(const modularInt &m) { n = m.n; return *this; }

  modularInt operator+(modularInt m) { return (n+m.n)%MOD; }
  modularInt operator-(modularInt m) { return (n+MOD-m.n)%MOD; }
  modularInt operator*(modularInt m) { return (1LL*n*m.n)%MOD; }
  modularInt pow(long long int e) { modularInt r = 1, a = *this; while(e) { if(e&1) r=r*a; a=a*a; e>>=1; } return r; }
  modularInt inv() { return pow(MOD-2); }
  modularInt operator/(modularInt m) { return m.inv()*n; }

  modularInt operator+=(modularInt m) { n=(n+m.n)%MOD; return *this; }
  modularInt operator-=(modularInt m) { n=(n+MOD-m.n)%MOD; return *this; }
  modularInt operator*=(modularInt m) { n=(1LL*n*m.n)%MOD; return *this; }
  modularInt operator/=(modularInt m) { n=(m.inv()*n).n; return *this; }
  bool operator==(modularInt m) { return n == m.n; }

  friend std::ostream& operator<<(std::ostream& os, const modularInt& n) { return os<<n.n; }
};

#else
#endif
