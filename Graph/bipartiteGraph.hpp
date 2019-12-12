#include <array>
#include <vector>
#include <utility>

class BipartiteGraph {
public:
  BipartiteGraph(int n, int m) : n(n), m(m) {
    edges.resize(n);
    visitedU.resize(n);
    visitedV.resize(m);
    matchU.resize(n, -1);
    matchV.resize(m, -1);
  }

  void add(int u, int v) {
    edges[u].push_back(v);
  }

  std::vector<std::pair<int, int>> doMatch() { // O(|V|*|E|)
    for(int i=0; i<n; i++) {
      fill(visitedU.begin(), visitedU.end(), false);
      dfs(i);
    }

    std::vector<std::pair<int, int>> matches;
    for(int i=0; i<n; i++) {
      if(matchU[i] != -1) matches.emplace_back(i, matchU[i]);
    }

    return matches;
  }

  // NOTE: Need to call doMatch() before call this.
  std::array<std::vector<int>, 2> getVertexCover(bool independentSet=false) {
    fill(visitedU.begin(), visitedU.end(), false);
    fill(visitedV.begin(), visitedV.end(), false);

    std::array<std::vector<int>, 2> cover;
    for(int i=0; i<n; i++) if(matchU[i] == -1) alternate(i);

    for(int i=0; i<n; i++) if(!visitedU[i]^independentSet) cover[0].push_back(i);
    for(int i=0; i<m; i++) if(visitedV[i]^independentSet) cover[1].push_back(i);

    return cover;
  }

  void resetMatch() {
    fill(matchU.begin(), matchU.end(), -1);
    fill(matchV.begin(), matchV.end(), -1);
  }

private:
  int n, m;
  std::vector<std::vector<int>> edges;
  std::vector<int> matchU, matchV;
  std::vector<char> visitedU, visitedV;

  bool dfs(int u) {
    if(visitedU[u]) return false;
    visitedU[u] = true;
    for(int v : edges[u]) {
      if (matchV[v] == -1 || dfs(matchV[v])) {
        matchU[u] = v; matchV[v] = u;
        return true;
      }
    }
    return false;
  }

  void alternate(int u) {
    visitedU[u] = true;
    for(int v : edges[u]) {
      if (!visitedV[v]) {
        visitedV[v] = true;
        alternate(matchV[v]);
      }
    }
  }
};
