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
      b[idx] ^= v;
    }

    int sum = 0;
    for(int i=1; i<=30; i++) {
      sum ^= b[i];
      assert(sum == a.query(i));
    }
  }

  { // 2D default (plus)
    FenwickTree2D<int> a(20, 30);
    std::vector<std::vector<int>> b(20+1, std::vector<int>(30+1, 0));

    for(int i=1; i<=200; i++) {
      int idx1 = rng()%20 + 1, idx2 = rng()%30 + 1;
      int v = rng()%100;
      a.update(idx1, idx2, v);
      b[idx1][idx2] += v;
    }

    for(int i=1; i<=20; i++) for(int j=1; j<=30; j++) b[i][j] += b[i][j-1];
    for(int j=1; j<=30; j++) for(int i=1; i<=20; i++) b[i][j] += b[i-1][j];

    for(int i=1; i<=20; i++) {
      for(int j=1; j<=30; j++) {
        assert(a.query(i, j) == b[i][j]);
      }
    }
  }

}
