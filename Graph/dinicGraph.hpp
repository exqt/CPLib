#include <vector>
#include <queue>

class DinicGraph {
public:
  struct Edge {
    int v;
    int cap;
    int flow;
    Edge *dual;

    Edge(int v, int cap) : v(v), cap(cap), flow(0), dual(nullptr) {}
    int residual() { return cap - flow; }
  };

  int n;
  std::vector<std::vector<Edge*>> adj;
  static int INF;

  DinicGraph(int n) : n(n) {
    adj.resize(n);
    work.resize(n);
    lvl.resize(n);
  }

  void addEdge(int u, int v, int cap) {
    Edge *ef = new Edge(v, cap);
    Edge *eb = new Edge(u, 0);
    ef->dual = eb;
    eb->dual = ef;
    adj[u].push_back(ef);
    adj[v].push_back(eb);
  }

  int maxFlow(int src, int sink) {
    int totalFlow = 0;
    while (bfs(src, sink)) {
      fill(work.begin(), work.end(), 0);
      while (1) {
        int f = dfs(src, sink, INF);
        if (!f) break;
        totalFlow += f;
      }
    }
    return totalFlow;
  }

private:
  std::vector<int> lvl;
  std::vector<int> work;

  bool bfs(int src, int sink) {
    fill(lvl.begin(), lvl.end(), -1);
    lvl[src] = 0;
    queue<int> Q;
    Q.push(src);

    while (Q.size()) {
      int here = Q.front();
      Q.pop();
      for (Edge *e : adj[here]) {
        if (lvl[e->v] == -1 && e->residual() > 0) {
          lvl[e->v] = lvl[here] + 1;
          Q.push(e->v);
        }
      }
    }

    return lvl[sink] != -1;
  }

  int dfs(int here, int dest, int f) {
    if (here == dest) return f;
    for (int &i = work[here]; i < (int)adj[here].size(); i++) {
      Edge *e = adj[here][i];
      if (lvl[e->v] == lvl[here] + 1 && e->residual() > 0) {
        int df = dfs(e->v, dest, min(e->residual(), f));
        if (df > 0) {
          e->flow += df;
          e->dual->flow -= df;
          return df;
        }
      }
    }
    return 0;
  }
};
int DinicGraph::INF = 1000000000;
