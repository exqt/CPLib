#include "types.hpp"
#include <cmath>
#include <algorithm>
#include <utility>

using vec = vec2<double>;
struct Circle { vec p; double r; };
struct Line { vec pt; vec normal; };
const double PI = acos(-1);
const double EPS = 1e-7;

auto getOuters = [](Circle a, Circle b) {
  if(a.r < b.r) std::swap(a, b);   

  vec ab = b.p - a.p;
  double ang = acos((a.r-b.r)/ab.length());
  
  vec t1 = ab.rotate(+ang).unit();
  Line L1 = {a.p + t1.scale(a.r), t1};    
  vec t2 = ab.rotate(-ang).unit();
  Line L2 = {a.p + t2.scale(a.r), t2};    
  
  return std::make_pair(L1, L2);
};

auto getInners = [](Circle a, Circle b) {
  vec ab = b.p - a.p;
  double prop = (a.r)/(a.r+b.r);
  double ang = acos(a.r / (prop*ab.length()));

  vec t1 = ab.rotate(+ang).unit();
  Line L1 = {a.p + t1.scale(a.r), t1};    
  vec t2 = ab.rotate(-ang).unit();
  Line L2 = {a.p + t2.scale(a.r), t2};    
  
  return std::make_pair(L1, L2);
};
  