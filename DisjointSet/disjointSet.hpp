#include <vector>

// O(1)
class DisjointSet {
public:
  DisjointSet(int n) : n(n) {
    par.resize(n);
    sz.resize(n, 1);
    for (int i = 0; i < n; i++) par[i] = i;
  }

  int find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  bool merge(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px == py) return false;

    par[px] = py;
    sz[py] += sz[px];
    return true;
  }

  int getGroupSize(int x) { return sz[find(x)]; }

private:
  int n;
  std::vector<int> par, sz;
};

// O(logN)
class DisjointSet2 {
public:
  DisjointSet2(int n) : n(n) {
    par.resize(n);
    group.resize(n);
    for (int i = 0; i < n; i++) par[i] = i;
    for (int i = 0; i < n; i++) group[i].push_back(i);;
  }

  int find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  bool merge(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px == py) return false;
    if(group[px].size() > group[py].size()) std::swap(px, py);

    par[px] = py;
    for(int t : group[px]) group[py].push_back(t);

    return true;
  }

  std::vector<int> getGroup(int x) { return group[find(x)]; }

private:
  int n;
  std::vector<int> par;
  std::vector<std::vector<int>> group;
};
