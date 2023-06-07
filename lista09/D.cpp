#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define MAXN 200000
#define LOG 17

int dp[MAXN + 1][LOG + 1];

void dfs(vector<vector<int>> & graph, int vertex, int parent, vector<int> & depth) {
  dp[vertex][0] = parent;

  for (int i = 1; i <= LOG; i++) {
    dp[vertex][i] = dp[dp[vertex][i - 1]][i - 1];
  }

  for (const int & adj : graph[vertex]) {
    if (adj == parent) continue;

    depth[adj] = depth[vertex] + 1;
    dfs(graph, adj, vertex, depth);
  }
}

int lowest_common_ancestor(int a, int b, vector<int> & depth) {
  if (depth[b] > depth[a]) {
    int c = a;
    a = b;
    b = c;
  }

  for (int i = LOG; i >= 0; i--) {
    if (depth[b] > depth[a] - (1 << i)) continue;

    a = dp[a][i];
  }

  if (a == b) {
    return b;
  }

  for (int i = LOG; i >= 0; i--) {
    if (dp[a][i] == dp[b][i]) continue;

    a = dp[a][i];
    b = dp[b][i];
  }

  return dp[a][0];
}

int main() {
  vector<vector<int>> graph(MAXN + 1);
  vector<int> depth(MAXN + 1, 0);
  int n, q;

  cin >> n >> q;

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs(graph, 1, 0, depth);

  while (q > 0) {
    int a, b, lca;
    cin >> a >> b;

    lca = lowest_common_ancestor(a, b, depth);

    cout << depth[a] + depth[b] - 2 * depth[lca] << "\n";
    q -= 1;
  }

  return 0;
}
