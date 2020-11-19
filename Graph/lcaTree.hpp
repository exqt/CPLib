#include <vector>
#include <algorithm>

class LCATree {
  std::vector<std::vector<int>> adj;
  std::vector<int> depth;
  std::vector<std::vector<int>> parent;
  int n, lgn;

public:
  LCATree(int n) : n(n) {
    lgn = 0;
    int t = 1; while(t < n) { t *= 2; lgn++; }
    adj.resize(n+1);
    depth.resize(n+1, 0);
    parent.resize(lgn, std::vector<int>(n+1, 0)); 
  }
  
  void add(int x, int y) {
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int jump(int x, int d) {
    for(int i=0; i<lgn; i++) if(d & (1<<i)) x = parent[i][x];
    return x;
  }

  int lca(int x, int y) {
    if(depth[x] < depth[y]) std::swap(x, y);
    int diff = depth[x] - depth[y];

    x = jump(x, diff);
    if(x == y) return x;

    for(int i=lgn-1; i>=0; i--) {
      if(parent[i][x] != parent[i][y]) {
        x = parent[i][x];
        y = parent[i][y];
      }
    }

    return std::max(1, parent[0][x]);
  }

  int dist(int x, int y) {
    int a = lca(x, y);
    return depth[x] + depth[y] - 2*depth[a];
  }

  int mid(int x, int y) {
    int d = dist(x, y);
    if(d % 2) return -1;

    if(depth[x] < depth[y]) std::swap(x, y);
    return jump(x, d/2);
  }

  void process() {
    dfs(1, 0);
    for(int i=1; i<lgn; i++) {
      for(int j=1; j<=n; j++) {
        parent[i][j] = parent[i-1][parent[i-1][j]];
      }
    }
  }
  
private:
  void dfs(int x, int prv) {
    depth[x] = depth[prv]+1;
    parent[0][x] = prv;
    for(int y : adj[x]) 
      if(y != prv) dfs(y, x);
  }
};
