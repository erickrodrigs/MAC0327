#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> & graph, int vertex, int parent, vector<vector<int>> & dp, vector<int> & depth, int logn) {
  dp[vertex][0] = parent;

  for (int i = 1; i <= logn; i++) {
    dp[vertex][i] = dp[dp[vertex][i - 1]][i - 1];
  }

  for (const int & adj : graph[vertex]) {
    if (adj == parent) continue;

    depth[adj] = depth[vertex] + 1;
    dfs(graph, adj, vertex, dp, depth, logn);
  }
}

int lowest_common_ancestor(vector<vector<int>> & dp, int a, int b, vector<int> & depth, int logn) {
  if (depth[b] > depth[a]) {
    int c = a;
    a = b;
    b = c;
  }

  for (int i = logn; i >= 0; i--) {
    if (depth[b] > depth[a] - pow(2, i)) continue;

    a = dp[a][i];
  }

  if (a == b) {
    return b;
  }

  for (int i = logn; i >= 0; i--) {
    if (dp[a][i] == dp[b][i]) continue;

    a = dp[a][i];
    b = dp[b][i];
  }

  return dp[a][0];
}

int main() {
  vector<vector<int>> graph, dp;
  vector<int> depth;
  int n, q, logn;

  cin >> n >> q;

  logn = ceil(log2(n));
  graph.resize(n + 1);
  depth.resize(n + 1, 0);
  dp.resize(n + 1, vector<int>(logn + 1, -1));

  for (int i = 2; i <= n; i++) {
    int t;
    cin >> t;
    graph[t].push_back(i);
  }

  dfs(graph, 1, 1, dp, depth, logn);

  while (q > 0) {
    int a, b;
    cin >> a >> b;
    cout << lowest_common_ancestor(dp, a, b, depth, logn) << "\n";
    q -= 1;
  }

  return 0;
}
