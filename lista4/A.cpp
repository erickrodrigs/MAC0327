#include <bits/stdc++.h>
using namespace std;

#define SIZE 4001

int memo[SIZE];

int dp(int n, int a, int b, int c) {
    if (memo[n] != INT_MIN) {
        return memo[n];
    }
    
    if (n == 0) {
        return 0;
    }
    
    int maximum = INT_MIN;
    
    if (n - a >= 0) {
        maximum = max(maximum, 1 + dp(n - a, a, b, c));
    }
    
    if (n - b >= 0) {
        maximum = max(maximum, 1 + dp(n - b, a, b, c));
    }
    
    if (n - c >= 0) {
        maximum = max(maximum, 1 + dp(n - c, a, b, c));
    }
    
    memo[n] = maximum;
    return memo[n];
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    for (int i = 0; i < SIZE; i++) {
        memo[i] = INT_MIN;
    }
    
    cout << dp(n, a, b, c) << endl;

    return 0;
}
