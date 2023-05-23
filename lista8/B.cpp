#include <bits/stdc++.h>
using namespace std;

int find(vector<int> & repr, int a) {
  if (a == repr[a]) return a;

  repr[a] = find(repr, repr[a]);

  return repr[a];
}

void join(vector<int> & repr, vector<int> & size, int a, int b) {
  a = find(repr, a);
  b = find(repr, b);

  if (a == b) return;

  if (size[a] < size[b]) {
    repr[a] = b;
    size[b] += size[a];
  } else {
    repr[b] = a;
    size[a] += size[b];
  }
}

bool same_set(vector<int> & repr, int a, int b) {
  return find(repr, a) == find(repr, b);
}

pair<int, int> sorted_pair(const pair<int, int> & pair) {
  return pair.first < pair.second ? make_pair(pair.first, pair.second) : make_pair(pair.second, pair.first);
}

void sort_answer(vector<pair<int, int>> & answer) {
  for (int i = 0; i < answer.size(); i++) {
    answer[i] = sorted_pair(answer[i]);
  }

  sort(answer.begin(), answer.end());
}

void print_min_spanning_tree(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> & pq, vector<pair<int, int>> & edges, int N) {
  vector<pair<int, int>> answer;
  vector<int> repr, size;
  int minimum_cost = 0;
  int num_edges = 0;

  for (int i = 0; i < N; i++) {
    repr.push_back(i);
    size.push_back(0);
  }

  while (!pq.empty()) {
    int u, v, w, repr_u, repr_v;
    pair<int, int> top = pq.top();
    pair<int, int> edge = edges[top.second];
    pq.pop();

    w = top.first;
    u = edge.first;
    v = edge.second;

    if (!same_set(repr, u, v)) {
      num_edges += 1;
      answer.push_back({ u, v });
      minimum_cost += w;
      join(repr, size, u, v);
    }
  }

  if (num_edges < N - 1) {
    cout << "Impossible" << endl;
    return;
  }

  sort_answer(answer);
  cout << minimum_cost << endl;
  for (const pair<int, int> & edge : answer) {
    int u, v;
    u = edge.first; v = edge.second;
    cout << u << " " << v << endl;
  }
}

int main() {
  while (true) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> edges;
    int N, M;

    cin >> N >> M;

    if (N == 0 && M == 0) break;

    for (int i = 0; i < M; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      edges.push_back({ u, v });
      pq.push({ w, i });
    }

    print_min_spanning_tree(pq, edges, N);
  }

  return 0;
}
