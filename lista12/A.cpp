#include <iostream>
#include <vector>
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

int get_substring_frequency(vector<int> & pi, string A, string B) {
  int i = 0, j = 0, frequency = 0;

  while (A.length() - i >= B.length() - j) {
    if (A[i] == B[j]) {
      i += 1;
      j += 1;
    }

    if (j == B.length()) {
      frequency += 1;
      j = pi[j - 1];
    } else if (i < A.length() && A[i] != B[j]) {
      if (j == 0) {
        i += 1;
      } else {
        j = pi[j - 1];
      }
    }
  }

  return frequency;
}

int main() {
  int t;

  cin >> t;

  for (int i = 1; i <= t; i++) {
    string A, B;
    vector<int> pi;

    cin >> A >> B;

    pi = kmp(B.length(), B.data());

    cout << "Case " << i << ": " << get_substring_frequency(pi, A, B) << "\n";
  }

  return 0;
}
