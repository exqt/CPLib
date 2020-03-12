#include "rangeSegmentTree.hpp"

void testSegmentTree() {
  {
    AddRangeSegmentTree<int> T(10);
    T.set(2, 5, 1);
    T.set(3, 10, 2);
    T.set(4, 7, 4);

    // 1 2 3 4 5 6 7 8 9 0
    // 0 1 1 1 1 0 0 0 0 0
    // 0 0 2 2 2 2 2 2 2 2
    // 0 0 0 4 4 4 4 0 0 0

    assert(T.get(1, 10) == 1*4 + 2*8 + 4*4);
    assert(T.get(3, 6) == 1*3 + 2*4 + 4*3);
    assert(T.get(7) == 6);
  }
}
