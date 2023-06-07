#include <iostream>
using namespace std;

int main() {
  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    int x1, y1, x2, y2, M;

    cout << "Case " << i << ":\n";

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> M;

    while (M > 0) {
      int x, y;
      bool within;

      cin >> x >> y;

      within = (x >= x1 && x <= x2 && y >= y1 && y <= y2);

      if (within) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }

      M -= 1;
    }
  }

  return 0;
}
