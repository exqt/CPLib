#include <algorithm>
#include <cassert>
#include "disjointSet.hpp"

void testDisjointSet() {
  {
    DisjointSet djs(10);

    assert(djs.find(0) == 0);
    assert(djs.find(3) == 3);

    assert(djs.merge(1, 2));
    assert(djs.merge(3, 4));

    assert(djs.find(2) != djs.find(3));
    assert(djs.find(1) == djs.find(2));

    assert(djs.getGroupSize(2) == 2);
    assert(djs.getGroupSize(4) == 2);

    assert(djs.merge(4, 5));
    assert(!djs.merge(4, 5));
    assert(djs.getGroupSize(4) == 3);

    assert(djs.merge(1, 4));
    assert(djs.getGroupSize(4) == 5);
  }

  {
    DisjointSet2 djs(10);

    assert(djs.find(0) == 0);
    assert(djs.find(3) == 3);

    assert(djs.merge(1, 2));
    assert(djs.merge(3, 4));

    assert(djs.find(2) != djs.find(3));
    assert(djs.find(1) == djs.find(2));

    assert(djs.getGroup(2).size() == 2);
    assert(djs.getGroup(4).size() == 2);

    assert(djs.merge(4, 5));
    assert(!djs.merge(4, 5));
    std::vector<int> g1 = djs.getGroup(4);
    std::sort(g1.begin(), g1.end());
    assert(g1 == std::vector<int>({3, 4, 5}));

    assert(djs.merge(1, 4));
    std::vector<int> g2 = djs.getGroup(4);
    std::sort(g2.begin(), g2.end());
    assert(g2 == std::vector<int>({1, 2, 3, 4, 5}));
  }
}
