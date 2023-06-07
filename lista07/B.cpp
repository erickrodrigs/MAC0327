#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> getStartAndDestinationPositions(string start, string destination) {
    int startRow = start[0] - 'a';
    int startCol = start[1] - '0' - 1;
    int destinationRow = destination[0] - 'a';
    int destinationCol = destination[1] - '0' - 1;

    return {
        { startRow, startCol },
        { destinationRow, destinationCol }
    };
}

vector<pair<int, int>> getNextPositions(int row, int col) {
    return {
        { row + 1, col + 2 },
        { row + 1, col - 2 },
        { row - 1, col + 2 },
        { row - 1, col - 2 },
        { row + 2, col + 1 },
        { row + 2, col - 1 },
        { row - 2 , col + 1 },
        { row - 2 , col - 1 }
    };
}

bool isWithinBoundaryOfTheChessboard(int row, int col) {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

int getMinimumNumberOfMoves(pair<int, int> start, pair<int, int> destination) {
    vector<vector<int>> distance(8, vector<int>(8, -1));
    queue<pair<int, int>> queue;

    queue.push(start);
    distance[start.first][start.second] = 0;

    while (!queue.empty()) {
        pair<int, int> currentPosition = queue.front();
        int row = currentPosition.first;
        int col = currentPosition.second;

        if (row == destination.first && col == destination.second) {
            return distance[row][col];
        }

        queue.pop();

        for (const pair<int, int> & position : getNextPositions(row, col)) {
            int nextRow = position.first;
            int nextCol = position.second;

            if (!isWithinBoundaryOfTheChessboard(nextRow, nextCol)) continue;

            if (distance[nextRow][nextCol] == -1) {
                distance[nextRow][nextCol] = distance[row][col] + 1;
                queue.push({ nextRow, nextCol });
            }
        }
    }

    return 0;
}

int main() {
    int t;

    cin >> t;

    while (t > 0) {
        vector<pair<int, int>> positions;
        string start, destination;
        
        cin >> start >> destination;

        positions = getStartAndDestinationPositions(start, destination);

        cout << getMinimumNumberOfMoves(positions[0], positions[1]) << endl;
        
        t -= 1;
    }

    return 0;
}
