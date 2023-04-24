#include <bits/stdc++.h>
using namespace std;

#define SIZE 1001
#define MOD 1000000007

int dp[SIZE][SIZE];

int countPaths(int row, int col, int m, int n, vector<string> & grid) {
    if (row == m || col == n) {
        return 0;
    }
    
    if (grid[row][col] == '*') {
        return 0;
    }
    
    if (row == m - 1 && col == n - 1) {
        return 1;
    }
    
    if (dp[row][col] != -1) {
        return dp[row][col];
    }
    
    dp[row][col] = (countPaths(row + 1, col, m, n, grid) % MOD + countPaths(row, col + 1, m, n, grid) % MOD) % MOD;
    return dp[row][col];
}

int main() {
    int n, answer;
    vector<string> grid;
    
    cin >> n;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            dp[i][j] = -1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }
    
    answer = countPaths(0, 0, n, grid[0].size(), grid);
    cout << answer << endl;

    return 0;
}
