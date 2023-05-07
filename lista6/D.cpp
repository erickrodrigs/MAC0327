#include <iostream>
#include <vector>
using namespace std;

#define MAX 200000

void dfs(vector<vector<int>> & graph, int vertex, vector<bool> & visited, vector<int> & distance) {
    visited[vertex] = true;

    for (const int & neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            distance[neighbor] = distance[vertex] + 1;
            dfs(graph, neighbor, visited, distance);
        }
    }
}

int get_tree_diameter(vector<vector<int>> & graph, int start_vertex) {
    if (start_vertex == 0) return 0;

    vector<bool> visited(MAX + 1, false);
    vector<int> distance(MAX + 1, 0);
    int vertex_with_max_distance = 0;
    int max_distance = 0;

    dfs(graph, start_vertex, visited, distance);

    for (int vertex = 1; vertex <= MAX; vertex++) {
        if (distance[vertex] > max_distance) {
            max_distance = distance[vertex];
            vertex_with_max_distance = vertex;
        }
    }

    visited.clear();
    distance.clear();
    visited.resize(MAX + 1, false);
    distance.resize(MAX + 1, 0);
    max_distance = 0;
    
    dfs(graph, vertex_with_max_distance, visited, distance);

    for (int vertex = 0; vertex <= graph.size(); vertex++) {
        if (distance[vertex] > max_distance) {
            max_distance = distance[vertex];
        }
    }

    return max_distance;
}

int main() {
    vector<vector<int>> graph(MAX + 1, vector<int>());
    int n, start_vertex = 0; // it does not matter which vertex choose to start

    cin >> n;

    while (n > 1) {
        int u, v;

        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
        start_vertex = v;

        n -= 1;
    }

    cout << get_tree_diameter(graph, start_vertex) << endl;

    return 0;
}
