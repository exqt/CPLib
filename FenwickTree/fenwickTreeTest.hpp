#include <vector>
#include <random>
#include <cassert>
#include "fenwickTree.hpp"

void testFenwickTree() {
  std::mt19937 rng(1);

  { // 1D default (plus)
    FenwickTree<int> a(30);
    std::vector<int> b(30+1, 0);

    for(int i=1; i<=200; i++) {
      int idx = rng()%30 + 1;
      int v = rng()%100 - 100;
      a.update(idx, v);
      b[idx] += v;
    }

    int sum = 0;
    for(int i=1; i<=30; i++) {
      sum += b[i];
      assert(sum == a.query(i));
    }
  }

  { // 1D XOR
    FenwickTree<int, std::bit_xor<int>> a(30);
    std::vector<int> b(30+1, 0);

    for(int i=1; i<=200; i++) {
      int idx = rng()%30 + 1;
      int v = rng()%100;
      a.update(idx, v);
      b[i] ^= v;
    }

    int sum = 0;
    for(int i=1; i<=30; i++) {
      sum ^= b[i];
      assert(sum == a.query(i));
    }
  }

}
