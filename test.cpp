#include <iostream>

#include "FenwickTree/fenwickTreeTest.hpp"
#include "Geometry/typesTest.hpp"
#include "Geometry/convexHullTest.hpp"

int main() {
  std::cout << "Testing Fenwick Tree.." << std::endl;
  testFenwickTree();

  std::cout << "Testing Geometry Types.." << std::endl;
  testGeometryTypes();

  std::cout << "Testing Convex Hull.." << std::endl;
  testConvexHull();

  std::cout << "OK!" << std:: endl;
}
