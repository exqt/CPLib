#include <vector>
#include <stack>
#include <algorithm>

// tarjan
class SCCGraph {
public:
  SCCGraph(int n) {
    size = n;
    discovered.resize(n, -1);
    sccId.resize(n, -1);
    adj.resize(n);
  }

  void addEdge(int x, int y) {
    adj[x].push_back(y);
  }

  void solve() {
    for (int i = 0; i < size; i++)
      if (discovered[i] == -1)
        tarjan(i);
  }

  int getId(int i) {
    return sccId[i];
  }

private:
  std::vector<std::vector<int>> adj;
  std::vector<int> discovered;
  std::vector<int> sccId;
  int counter = 0;
  int sccCounter = 0;
  std::stack<int> ST;
  int size = 0;

  int tarjan(int here) {
    discovered[here] = counter++;
    int ret = discovered[here];

    ST.push(here);
    for (auto there : adj[here]) {
      if (discovered[there] == -1) {
        ret = std::min(ret, tarjan(there));
      }
      else if (discovered[here] > discovered[there] && sccId[there] == -1) {
        ret = std::min(ret, discovered[there]);
      }
    }

    if (ret == discovered[here]) {
      while (true) {
        int t = ST.top();
        ST.pop();
        sccId[t] = sccCounter;
        if (t == here)
          break;
      }

      sccCounter++;
    }

    return ret;
  }
};
