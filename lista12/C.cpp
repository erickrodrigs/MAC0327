#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T> vector<int> kmp(int sz, const T s[]) {
  vector<int> pi(sz);
  for (int i = 1; i < sz; i++) {
    int &l = pi[i];
    l = pi[i-1];
    
    while(l > 0 && s[i] != s[l])
      l = pi[l-1];

    if(s[i] == s[l]) l++;
  }

  return pi;
};

int get_prefix(vector<int> & pi, string A, string B) {
  int j = 0;

  for (int i = 0; i < A.length(); i++) {
    while (j > 0 && A[i] != B[j]) {
      j = pi[j - 1];
    }

    j += 1;
  }

  return j;
}

int main() {
  int t;

  cin >> t;

  for (int i = 1; i <= t; i++) {
    string A, B;
    vector<int> pi;

    cin >> A;

    B = string(A);

    reverse(B.begin(), B.end());

    pi = kmp(B.length(), B.data());

    cout << "Case " << i << ": " << 2 * A.length() - get_prefix(pi, A, B) << "\n";
  }

  return 0;
}
