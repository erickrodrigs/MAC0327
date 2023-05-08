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

bool is_valid_position(vector<string> & grid, int row, int col) {
    return row >= 0 &&
           row < grid.size() &&
           col >= 0 &&
           col < grid[row].length() &&
           grid[row][col] == '.'; 
}

void dfs(vector<string> & grid, int row, int col, int & remaining, int k) {
    if (remaining == k) return;

    grid[row][col] = '&'; // not to visit again
    remaining -= 1;

    for (const vector<int> & position : get_neighbors(row, col)) {
        int i = position.at(0);
        int j = position.at(1);

        if (is_valid_position(grid, i, j)) {
            grid[i][j] = '$'; // not to visit again
            dfs(grid, i, j, remaining, k);
        }
    }
}

void turn_cells_into_walls(vector<string> & grid, int n, int m, int k) {
    int remaining = 0;
    int start_row = 0, start_col = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                remaining += 1;
                start_row = i;
                start_col = j;
            }
        }
    }

    while (remaining > k) {
        dfs(grid, start_row, start_col, remaining, k);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '&') {
                grid[i][j] = '.';
            } else if (grid[i][j] == '.' || grid[i][j] == '$') {
                grid[i][j] = 'X';
            }
        }
    }
}

int main() {
    vector<string> grid;
    int n, m, k;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        grid.push_back(line);
    }

    turn_cells_into_walls(grid, n, m, k);
    for (int i = 0; i < n; i++) {
        cout << grid[i] << endl;
    }

    return 0;
}
