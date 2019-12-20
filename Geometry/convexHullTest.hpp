#include <vector>
#include <random>
#include <algorithm>
#include <cassert>
#include "convexHull.hpp"

void testConvexHull() {
  // y........
  // ^...@-@..
  // |../.@.\.
  // |.@..@@.@
  // |.|.@../.
  // |.@-@-@..
  // #----------> x
  {
    std::mt19937 rng(1);
    std::vector<vec2<int>> points = {
      {4, 5}, {6, 5},
      {5, 4},
      {2, 3}, {5, 3}, {6, 3}, {8, 3},
      {4, 2},
      {2, 1}, {4, 1}, {6, 1},
    };

    std::shuffle(points.begin(), points.end(), rng);

    std::vector<vec2<int>> answer = {
      {4, 5}, {6, 5},
      {2, 3}, {8, 3},
      {2, 1}, {6, 1},
    };

    std::vector<vec2<int>> out = getConvexHull<int>(points);

    auto vec2comp = [](const vec2<int> a, const vec2<int> b) {
      return a.x != b.x ? a.x < b.x : a.y < b.y;
    };

    std::sort(answer.begin(), answer.end(), vec2comp);
    std::sort(out.begin(), out.end(), vec2comp);

    assert(answer == out);
  }
}

