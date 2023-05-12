#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

void printPath(vector<int> & parent, int end) {
    vector<int> path;
    int currentVertex = end;

    path.push_back(end);

    currentVertex = parent[currentVertex];
    while (currentVertex != -1) {
        path.push_back(currentVertex);
        currentVertex = parent[currentVertex];
    }

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }

    cout << endl;
}

void dijkstra(vector<vector<pair<int, int>>> & graph, int n, int m) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    vector<int> visited(n + 1, false);

    pq.push({ 0, 1 });
    dist[1] = 0;

    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if (u == n) break;

        visited[u] = true;

        for (const pair<int, int> & adjacent : graph[u]) {
            int v = adjacent.first;
            int cost = adjacent.second;

            if (!visited[v] && dist[v] > dist[u] + cost) {
                parent[v] = u;
                dist[v] = dist[u] + cost;
                pq.push({ dist[v], v });
            }
        }
    }

    if (dist[n] == INT_MAX) {
        cout << -1 << endl;
        return;
    }

    printPath(parent, n);
}

int main() {
    vector<vector<pair<int, int>>> graph;
    int n, m;

    cin >> n >> m;

    graph.resize(n + 1, vector<pair<int, int>>());

    for (int i = 0; i < m; i++) {
        int from, to, weight;

        cin >> from >> to >> weight;

        graph[from].push_back({ to, weight });
        graph[to].push_back({ from, weight });
    }

    dijkstra(graph, n, m);

    return 0;
}
