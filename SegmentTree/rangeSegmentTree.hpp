#include <vector>
#include <functional>

template<typename T, typename OP, T initV>
class RangeSegmentTree {
public:
  RangeSegmentTree(int n) : n(n) {
    p2 = 1;
    while (p2 < n) p2 *= 2;

    node.resize(2*p2, initV);
    lazy.resize(2*p2, initV);
  }

  int size() { return n; }
  void set(int l, int r, T v) { _set(l, r, v, 1, p2, 1); }
  void set(int l, T v) { _set(l, l, v, 1, p2, 1); }
  T get(int l) { return _get(l, l, 1, p2, 1); }
  T get(int l, int r) { return _get(l, r, 1, p2, 1); }

protected:
  int n, p2;
  std::vector<T> node;
  std::vector<T> lazy;
  OP op;

  virtual void _propagate(int p, int q, int id) = 0;

  void _set(int l, int r, T v, int p, int q, int id) {
    _propagate(p, q, id);

    if (r < p || q < l) return;
    else if (l <= p && q <= r) {
      lazy[id] = op(lazy[id], v);
      _propagate(p, q, id);
      return;
    }
    else {
      int mid = (p+q)/2;
      _set(l, r, v, p, mid, 2*id);
      _set(l, r, v, mid + 1, q, 2*id+1);
      if (p != q) node[id] = op(node[2*id], node[2*id+1]);
    }
  }

  T _get(int l, int r, int p, int q, int id) {
    _propagate(p, q, id);

    if (r < p || q < l) return 0;
    else if (l <= p && q <= r) return node[id];
    else {
      int mid = (p+q)/2;
      return op(_get(l, r, p, mid, 2*id), _get(l, r, mid+1, q, 2*id+1));
    }
  }
};

template<typename T>
class AddRangeSegmentTree : public RangeSegmentTree<T, std::plus<T>, 0> {
public:
  AddRangeSegmentTree(int n) : RangeSegmentTree<T, std::plus<T>, 0>(n) {}

private:
  void _propagate(int p, int q, int id) {
    if (this->lazy[id] != 0) {
      if (id < this->p2) {
        this->lazy[2*id] = this->lazy[2*id] + this->lazy[id];
        this->lazy[2*id+1] = this->lazy[2*id+1] + this->lazy[id];
      }

      this->node[id] += this->lazy[id] * (q-p+1);
      this->lazy[id] = 0;
    }
  }
};

template<typename T>
class XorRangeSegmentTree : public RangeSegmentTree<T, std::bit_xor<T>, 0> {
public:
  XorRangeSegmentTree(int n) : RangeSegmentTree<T, std::bit_xor<T>, 0>(n) {}

private:
  void _propagate(int p, int q, int id) {
    if (this->lazy[id] != 0) {
      if (id < this->p2) {
        this->lazy[2*id] ^= this->lazy[id];
        this->lazy[2*id+1] ^= this->lazy[id];
      }

      this->node[id] ^= this->lazy[id] * ((q-p+1)%2);
      this->lazy[id] = 0;
    }
  }
};
