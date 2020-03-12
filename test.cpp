#include <iostream>

#include "DisjointSet/disjointSetTest.hpp"
#include "FenwickTree/fenwickTreeTest.hpp"
#include "Geometry/typesTest.hpp"
#include "Geometry/convexHullTest.hpp"
#include "Math/modularIntTest.hpp"
#include "Math/polynomialTest.hpp"
#include "SAT/twoSATTest.hpp"

int main() {
  std::cout << "Testing Disjoint Set.." << std::endl;
  testDisjointSet();

  std::cout << "Testing Fenwick Tree.." << std::endl;
  testFenwickTree();

  std::cout << "Testing Geometry Types.." << std::endl;
  testGeometryTypes();

  std::cout << "Testing Convex Hull.." << std::endl;
  testConvexHull();

  std::cout << "Testing Modular Int.." << std::endl;
  testModularInt();

  std::cout << "Testing Polynomial.." << std::endl;
  testPolynomial();

  std::cout << "Testing SAT.." << std::endl;
  testTwoSAT();

  std::cout << "OK!" << std:: endl;
}
