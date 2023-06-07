#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100000

int getMinNumberOfJumps(vector<vector<int>> & graph, int n) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> distance(MAX + 10, 0);
    
    pq.push({ 1, 0 });
    distance[0] = 1;
    
    while (!pq.empty()) {
        pair<int, int> distanceAndIndex = pq.top();
        int currentDistance = distanceAndIndex.first;
        int index = distanceAndIndex.second;

        pq.pop();
        
        for (const int & neighbor : graph[index]) {
            if (distance[neighbor] == 0 || distance[index] + 1 < distance[neighbor]) {
                if (neighbor >= MAX) {
                    distance[neighbor] = distance[index];
                } else {
                    distance[neighbor] = distance[index] + 1;
                }
                pq.push({ distance[neighbor], neighbor });
            }
        }
    }

    return distance[n - 1] - 1;
}

int main() {
    vector<vector<int>> graph(MAX + 10, vector<int>()); // ten more for each digit (0 to 9)
    string digits;
    int n;

    cin >> digits;
    n = digits.length();

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            graph[i].push_back(i - 1);
        }
        if (i < n - 1) {
            graph[i].push_back(i + 1);
        }

        graph[i].push_back(digits[i] - '0' + MAX);
        graph[digits[i] - '0' + MAX].push_back(i);
    }

    cout << getMinNumberOfJumps(graph, n) << endl;

    return 0;
}
