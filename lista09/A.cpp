#include <iostream>
using namespace std;

#define MAXN 200005
#define LOGK 31

int prox[MAXN];
int dp[MAXN][LOGK];

int go(int x, int k) {
  for (int b = LOGK - 1; b >= 0; b--) {
    int pot = 1 << b;
    if (k >= pot) {
      k -= pot;
      x = dp[x][b];
    }
  }

  return x;
}


int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    prox[i] = t;
  }

  for (int i = 1; i <= n; i++) {
    dp[i][0] = prox[i];
  }

  for (int b = 1; b < LOGK; b++) {
    for (int i = 1; i <= n; i++) {
      dp[i][b] = dp[dp[i][b - 1]][b - 1];
    }
  }

  while (q > 0) {
    int x, k;
    cin >> x >> k;
    cout << go(x, k) << "\n";
    q -= 1;
  }

  return 0;
}
