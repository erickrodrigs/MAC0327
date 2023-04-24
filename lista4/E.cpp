#include <bits/stdc++.h>
using namespace std;

#define SIZE 3001

int dp[SIZE][SIZE];

void lcs(string s, string t) {
    int m = s.length();
    int n = t.length();
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

string buildLongestString(string s, string t) {
    int m = s.length();
    int n = t.length();
    string answer = "";
    
    while (m > 0 && n > 0) {
        if (s[m - 1] == t[n - 1]) {
            answer += t[n - 1];
            m -= 1;
            n -= 1;
        } else if (dp[m - 1][n] > dp[m][n - 1]) {
            m -= 1;
        } else {
            n -= 1;
        }
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    string s, t;
    cin >> s >> t;
    lcs(s, t);
    cout << buildLongestString(s, t) << endl;
    return 0;
}
