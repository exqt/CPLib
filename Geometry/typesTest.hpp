#include <cassert>
#include "types.hpp"

void testGeometryTypes() {
  { // vec2
    vec2<int> a = {1, 2};
    vec2<int> b = {3, 4};

    assert(a.dot(b) == 11);
    assert(a.cross(b) == -2);
    assert(a+b == vec2<int>(4, 6));
    assert(a-b == vec2<int>(-2, -2));
    assert(b.length() == 25);
  }

  { // vec3
    vec3<int> a = {1, 2, 3};
    vec3<int> b = {4, 5, 6};

    assert(a.dot(b) == 32);
    assert(a.cross(b) == vec3<int>(-3, 6, -3));
    assert(a+b == vec3<int>(5, 7, 9));
    assert(a-b == vec3<int>(-3, -3, -3));
    assert(a.length() == 14);
  }
}