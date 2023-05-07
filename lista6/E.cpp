#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

#define MAX 200001

void dfs(vector<vector<int>> &graph, int vertex, vector<bool> &visited, set<int> &nodes) {
    visited[vertex] = true;
    nodes.insert(vertex);

    for (const int &neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited, nodes);
        }
    }
}

int getNumberOfCyclicComponents(vector<vector<int>> &graph) {
    unordered_map<int, int> vertices_degree;
    vector<bool> visited(MAX, false);
    set<int> visited_nodes;
    int count_cyclic_components = 0;

    for (int vertex = 1; vertex <= MAX; vertex++) {
        if (graph[vertex].size() > 0) {
            vertices_degree[vertex] = graph[vertex].size();
        }
    }

    for (int vertex = 1; vertex <= MAX; vertex++) {
        if (graph[vertex].size() == 0) {
            continue;
        }

        if (!visited[vertex]) {
            visited_nodes.clear();
            int increment = 1;

            dfs(graph, vertex, visited, visited_nodes);

            for (const int &node : visited_nodes) {
                if (vertices_degree[node] != 2) {
                    increment = 0;
                    break;
                }
            }

            count_cyclic_components += increment;
        }
    }

    return count_cyclic_components;
}

int main() {
    vector<vector<int>> graph(MAX, vector<int>());
    int n, m;

    cin >> n >> m;

    while (m > 0) {
        int u, v;

        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);

        m -= 1;
    }

    cout << getNumberOfCyclicComponents(graph) << endl;

    return 0;
}
