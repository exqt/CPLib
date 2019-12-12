#include <algorithm>
#include <vector>

#include "Geometry/types.hpp"

template<class T>
std::vector<vec2<T>> getConvexHull(vector<vec2<T>> pts) {
  vec2<T> center = *min_element(pts.begin(), pts.end(),
    [](vec2<T> &a, vec2<T> &b) {
      if(a.y != b.y) return a.y < b.y;
      else return a.x < b.x;
    }
  );

  sort(pts.begin(), pts.end(),
    [&center](vec2<T> a, vec2<T> b) {
      a.x -= center.x; a.y -= center.y;
      b.x -= center.x; b.y -= center.y;

      if(b.x*a.y != a.x*b.y) return b.x*a.y < a.x*b.y;
      else return a.length() < b.length();
    }
  );

  vector<vec2<T>> S;
  S.push_back(pts[0]);
  S.push_back(pts[1]);

  for(int i=2; i<(int)pts.size(); i++) {
    while(S.size() >= 2 &&
    (S[(int)S.size()-2] - S[(int)S.size()-1]).cross(S[(int)S.size()-1] - pts[i]) <= 0)
      S.pop_back();
    S.push_back(pts[i]);
  }

  return S;
}
