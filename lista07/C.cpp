#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isConsecutive(char letter1, char letter2) {
    return letter2 - letter1 == 1;
}

bool isValidPosition(int row, int col, int H, int W) {
    return row >= 0 && row < H && col >= 0 && col < W;
}

vector<pair<int, int>> getAdjacents(int row, int col) {
    return {
        { row, col + 1 },
        { row + 1, col },
        { row, col - 1 },
        { row - 1, col },
        { row + 1, col + 1 },
        { row + 1, col - 1 },
        { row - 1, col + 1 },
        { row - 1, col - 1 }
    };
}

void buildDistanceOfConsecutiveLetters(vector<string> & grid, int row, int col, int H, int W, vector<vector<int>> & distance, int currentDistance) {
    char currentLetter = grid[row][col];
    distance[row][col] = currentDistance + 1;

    for (const pair<int, int> & adjacentPosition : getAdjacents(row, col)) {
        int newRow = adjacentPosition.first;
        int newCol = adjacentPosition.second;
        char adjacentLetter;

        if (!isValidPosition(newRow, newCol, H, W)) continue;

        adjacentLetter = grid[newRow][newCol];

        if (isConsecutive(currentLetter, adjacentLetter) && distance[row][col] + 1 > distance[newRow][newCol]) {
            buildDistanceOfConsecutiveLetters(grid, newRow, newCol, H, W, distance, distance[row][col]);
        }
    }
}

int main() {
    int t = 1;

    while (true) {
        vector<string> grid;
        vector<pair<int, int>> startingPositions;
        vector<vector<int>> distance;
        int longestPath = 0;
        int H, W;

        cin >> H >> W;

        if (H == 0 && W == 0) break;

        for (int i = 0; i < H; i++) {
            string row;
            cin >> row;
            grid.push_back(row);
            distance.push_back(vector<int>(W, 0));

            for (int j = 0; j < row.size(); j++) {
                if (grid[i][j] == 'A') {
                    startingPositions.push_back({ i, j });
                }
            } 
        }

        for (const pair<int, int> & position : startingPositions) {
            int i = position.first;
            int j = position.second;

            if (distance[i][j] == 0) {
                buildDistanceOfConsecutiveLetters(grid, i, j, H, W, distance, 0);
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (distance[i][j] > longestPath) {
                    longestPath = distance[i][j];
                }
            }
        }
        cout << "Case " << t << ": " << longestPath << endl;

        t += 1;
    }

    return 0;
}
