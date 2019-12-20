#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

template<class T>
std::vector<std::pair<T, int>> factorize(T n) {
  std::vector<std::pair<T, int>> factors;
  for(T i=2; i*i<=n; i++) {
    if(n % i == 0) {
      int cnt = 0;
      while(n % i == 0) {
        cnt++;
        n /= i;
      }
      factors.push_back({i, cnt});
    }
  }

  if(n != 1) factors.push_back({n, 1});
  return factors;
}

template<class T>
T phi(T n) {
  auto f = factorize(n);
  for(auto a : f) {
    n /= a.first;
    n *= a.first - 1;
  }
  return n;
}

int pow(int x, int y, int m) {
  int r = 1;
  while(y) {
    if(y%2) r = 1LL*r*x % m;
    x = 1LL*x*x % m;
    y /= 2;
  }
  return r;
}

long long crt2(int r1, int m1, int r2, int m2) {
  if(r2 > r1) {
    std::swap(r1, r2);
    std::swap(m1, m2);
  }

  int q2 = 1LL*(r1-r2)*pow(m2, phi(m1)-1, m1) % m1;
  return 1LL*m2*q2+r2;
}
