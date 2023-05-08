#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> get_neighbors(int row, int col) {
    return {
        { row, col + 1 },
        { row + 1, col },
        { row, col - 1 },
        { row - 1, col }
    };
}

bool is_valid_position(vector<string> & labyrinth, int row, int col, vector<vector<bool>> & visited) {
    return row >= 0 &&
           row < labyrinth.size() &&
           col >= 0 &&
           col < labyrinth[row].length() &&
           !visited[row][col] &&
           labyrinth[row][col] == '.';
}

void dfs(vector<string> & labyrinth, int row, int col, vector<vector<bool>> & visited, vector<vector<int>> & distance) {
    visited[row][col] = true;

    for (const vector<int> & position : get_neighbors(row, col)) {
        int i = position.at(0);
        int j = position.at(1);

        if (is_valid_position(labyrinth, i, j, visited)) {
            distance[i][j] = distance[row][col] + 1;
            dfs(labyrinth, i, j, visited, distance);
        }
    }
}

int get_maximum_rope_length(vector<string> & labyrinth, int c, int r) {
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    vector<vector<int>> distance(r, vector<int>(c, 0));
    vector<int> free_block_with_max_distance = { 0, 0 };
    int max_rope_length = 0;
    int start_row = 0, start_col = 0;
    int max_distance = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (labyrinth[i][j] == '.') {
                start_row = i;
                start_col = j;
                break;
            }
        }
    }

    dfs(labyrinth, start_row, start_col, visited, distance);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (labyrinth[i][j] == '.' && distance[i][j] > max_distance) {
                free_block_with_max_distance = { i, j };
                max_distance = distance[i][j];
            }
        }
    }

    visited.clear();
    distance.clear();
    visited.resize(r, vector<bool>(c, false));
    distance.resize(r, vector<int>(c, 0));

    dfs(labyrinth, free_block_with_max_distance.at(0), free_block_with_max_distance.at(1), visited, distance);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (labyrinth[i][j] == '.' && distance[i][j] > max_rope_length) {
                max_rope_length = distance[i][j];
            }
        }
    }

    return max_rope_length;
}

int main() {
    int t;

    cin >> t;

    while (t > 0) {
        vector<string> labyrinth;
        int c, r;

        cin >> c >> r;

        for (int i = 0; i < r; i++) {
            string s;
            cin >> s;
            labyrinth.push_back(s);
        }

        cout << "Maximum rope length is " << get_maximum_rope_length(labyrinth, c, r) << "." << endl;
        t -= 1;
    }
    return 0;
}
