#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 101

int getNumberOfMiceThatReachedExitCell(vector<vector<pair<int, int>>> & maze, int N, int E, int T) {
    int numberOfMiceThatReachedExit = 0;

    for (int i = 1; i <= N; i++) {
        queue<pair<int, int>> queue;
        vector<bool> visited(N, false);
        queue.push({ i, T });
        
        while (!queue.empty()) {
            pair<int, int> vertexAndTime = queue.front();
            int currentVertex = vertexAndTime.first;
            int currentTime = vertexAndTime.second;

            if (currentVertex == E) {
                numberOfMiceThatReachedExit += 1;
                break;
            }

            queue.pop();
            visited[i] = true;

            for (int i = 0; i < maze[currentVertex].size(); i++) {
                pair<int, int> neighborAndTimeNeeded = maze[currentVertex][i];
                int neighbor = neighborAndTimeNeeded.first;
                int timeNeeded = neighborAndTimeNeeded.second;

                if (!visited[neighbor] && currentTime - timeNeeded >= 0) {
                    queue.push({ neighbor, currentTime - timeNeeded });
                }
            }
        }
    }

    return numberOfMiceThatReachedExit;
}

int main() {
    vector<vector<pair<int, int>>> maze(MAX, vector<pair<int, int>>());
    int N, E, T, M;

    cin >> N >> E >> T >> M;

    for (int i = 0; i < M; i++) {
        int a, b, time;
        cin >> a >> b >> time;

        maze[a].push_back({ b, time });
    }

    cout << getNumberOfMiceThatReachedExitCell(maze, N, E, T) << endl;

    return 0;
}
