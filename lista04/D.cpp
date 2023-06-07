#include <bits/stdc++.h>
using namespace std;

#define MAX 101

int dp[MAX][2];

int countPathsOfWeightN(int n, int k, int d, int weight, bool state) {
    if (dp[weight][state] != -1) {
        return dp[weight][state];
    }
    
    if (weight > n) {
        return dp[weight][state] = 0;
    }
    
    if (weight == n && state) {
        return dp[weight][state] = 1;
    }
    
    int answer = 0;
    
    for (int i = 0; i < k; i++) {
        bool newState = state;
        if (weight + i + 1 <= n) {
            newState |= (i >= d - 1);
            answer += countPathsOfWeightN(n, k, d, weight + i + 1, newState) % 1000000007;
        }
        
        dp[weight][state] = answer;
    }
    
    return answer;
}

int main() {
    int n, k, d, answer = 0;
    
    cin >> n >> k >> d;
    
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j] = -1;
        }
    }
    
    for (int i = 0; i < k; i++) {
        bool state = (i >= d - 1);
        answer += countPathsOfWeightN(n, k, d, i + 1, state) % 1000000007;
    }
    
    cout << answer << endl;

    return 0;
}
