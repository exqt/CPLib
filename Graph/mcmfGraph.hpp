#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

class MCMFGraph {
public:
  static int INF;
  struct Edge {
    int u, v;
    int cap;
    int cost;
    int flow;
    Edge *dual;

    Edge(int u, int v, int cap, int cost) : u(u), v(v), cap(cap), cost(cost), flow(0), dual(nullptr) {}
    int residual() { return cap - flow; }
  };

  MCMFGraph(int n) : n(n) {
    adj.resize(n);
    dist.resize(n);
    inQ.resize(n);
    path.resize(n);
  }

  void addEdge(int u, int v, int cap, int cost) {
    Edge *ef = new Edge(u, v, cap, cost);
    Edge *eb = new Edge(v, u, 0, -cost);
    ef->dual = eb;
    eb->dual = ef;
    adj[u].push_back(ef);
    adj[v].push_back(eb);
  }

  std::pair<int,int> get(int src, int sink, int iter=INF) {
    int totalFlow = 0;
    int totalCost = 0;
    while(iter > 0 && spfa(src, sink)) {
      int f = INF;
      for(int p=sink; p!=src; p=path[p]->v) f = std::min(f, path[p]->dual->residual());
      for(int p=sink; p!=src; p=path[p]->v) {
        path[p]->dual->flow += f;
        path[p]->flow -= f;
        totalCost += path[p]->dual->cost * f;
      }
      iter--;
      totalFlow += f;
    }

    return {totalCost, totalFlow};
  }

private:
  int n;
  std::vector<std::vector<Edge*>> adj;
  std::vector<int> dist;
  std::vector<char> inQ;
  std::vector<Edge*> path;

  bool spfa(int src, int sink) {
    std::queue<int> Q;
    std::fill(dist.begin(), dist.end(), INF);
    std::fill(inQ.begin(), inQ.end(), false);
    std::fill(path.begin(), path.end(), nullptr);

    dist[src] = 0;
    Q.push(src);
    inQ[src] = 1;

    while(Q.size()) {
      int u = Q.front(); Q.pop();
      inQ[u] = 0;
      for(Edge* e : adj[u]) {
        if(e->residual() <= 0) continue;
        int v = e->v;
        int cost = e->cost;
        if(dist[v] > dist[u]+cost) {
          dist[v] = dist[u]+cost;
          path[v] = e->dual;
          if(!inQ[v]) {
            inQ[v] = 1;
            Q.push(v);
          }
        }
      }
    }

    return dist[sink] < INF;
  }
};
int MCMFGraph::INF = 1000000000;
