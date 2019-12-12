#include <vector>
#include <functional>

template<class T, class OP=std::plus<T>, T initV=0>
// NOTE: 1-index
class FenwickTree {
public:
  FenwickTree(int n) : n(n) {
    f.resize(n+1, initV);
  }

  void update(int x, T val) {
    for(; x <= n; x += x & (-x)) f[x] = op(f[x], val);
  }

  T query(int x) {
    T r = initV; for(; x; x -= x & (-x)) r = op(r, f[x]);
    return r;
  }

private:
  int n;
  std::vector<T> f;
  OP op;
};

template<class T, class OP=std::plus<T>, T initV=0>
class FenwickTree2D {
public:
  FenwickTree2D(int n, int m) : n(n) {
    f.resize(n+1, FenwickTree<T, OP, initV>(m));
  }

  void update(int x, int y, T val) {
    for(; x <= n; x += x & (-x)) f[x].update(y, val);
  }

  T query(int x, int y) {
    T r = initV; for(; x; x -= x & (-x)) r = op(r, f[x].query(y));
    return r;
  }

private:
  int n;
  std::vector<FenwickTree<T, OP, initV>> f;
  OP op;
};
