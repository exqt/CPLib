#include <vector>
#include "../Graph/sccGraph.hpp"

class twoSAT {
public:
  twoSAT(int size) : SCC(size * 2 + 1) {
    cl = size;
  }

  void add(int x, int y) {
    SCC.addEdge(-x + cl, y + cl);
    SCC.addEdge(-y + cl, x + cl);
  }

  bool possible() {
    SCC.solve();
    for (int i = 1; i <= cl; i++)
      if (SCC.getId(-i + cl) == SCC.getId(i + cl))
        return 0;

    return 1;
  }

  // NOTE: must call possible() before call this.
  std::vector<int> solution() {
    std::vector<int> v(cl + 1, 0);
    for (int i = 1; i <= cl; i++)
      v[i] = (SCC.getId(-i + cl) > SCC.getId(i + cl));
    return v;
  }

private:
  SCCGraph SCC;
  int cl;
};
