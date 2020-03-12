#include <cassert>
#include "twoSAT.hpp"

void testTwoSAT() {
  {
    twoSAT G(5);
    // 01101
    G.add(-1, -2);
    G.add(-1, 3);
    G.add(1, -4);
    G.add(2, -3);
    G.add(2, 4);
    G.add(-3, 4);
    G.add(5, 5);

    assert(G.possible() == true);
  }
}
