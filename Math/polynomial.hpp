#include <vector>
#include <ostream>
#include <iostream>

template <class T>
class Polynomial {
public:
  Polynomial(int n) : n(n) {
    co.resize(n+1, 0);
  };

  T& operator[](int x) { return co[x]; }
  const T operator[](int x) const { return x <= n ? co[x] : 0; }

  Polynomial<T> operator+(const Polynomial &o) {
    int d = n > o.n ? n : o.n;
    Polynomial r(d);
    for(int i=d; i>=0; i--) r[i] = co[i] + o[i];
    return r;
  }

  Polynomial<T> operator-(const Polynomial &o) {
    int d = n > o.n ? n : o.n;
    Polynomial r(d);
    for(int i=d; i>=0; i--) r[i] = co[i] - o[i];
    return r;
  }

  Polynomial<T> operator*(const Polynomial &o) {
    int d = n + o.n;
    Polynomial r(d);
    for(int i=0; i<=n; i++) {
      for(int j=0; j<=o.n; j++){
        r[i+j] += co[i] * o[j];
      }
    }
    return r;
  }

  T eval(T x) {
    T r = 0, b = 1;
    for(int i=0; i<=n; i++) {
      r += co[i] * b;
      b = b * x;
    }
    return r;
  }

  friend std::ostream& operator<<(std::ostream& os, const Polynomial<T>& p) {
    for(int i=p.degree(); i>=1; i--) {
      if(p[i]) {
        if(p[i] > 0 && i != p.degree()) os << '+';
        if(p[i] != -1 && p[i] != 1) os << p[i]; else if(p[i] == -1) os << '-';
        if(i>=1) os << "x";
        if(i>=2) os << "^" << i;
      }
    }
    if(p[0]) os << (p.degree() > 0 && p[0] >= 0 ? "+" : "") << p[0];
    return os;
  }

  int degree() const { return n; }

private:
  int n;
  std::vector<T> co;
};
