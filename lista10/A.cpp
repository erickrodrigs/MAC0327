#include <iostream>
using namespace std;

void get_point_location(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
  /**
   * ax + b = line
   * a = (y2 - y1) / (x2 - x1)
   * b = y1 - x1 * a
   * 
   * if (y3 - (x3 * a + b) > 0) left
   * else if (y3 - (x3 * a + b) == 0) touch
   * else right
   * 
   * y3 - x3 * a - b =
   * y3 - [(y2 - y1)/(x2 - x1)] * x3 - y1 + [(y2 - y1)/(x2 - x1)] * x1 =
   * [(x2 - x1) * y3 - (y2 - y1) * x3 - (x2 - x1) * y1 - (y2 - y1) * x1] / [(x2 - x1)] =
   * [(x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)] / [(x2 - x1)]
  */

  long long coefficient = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
  
  if (coefficient == 0) {
    cout << "TOUCH\n";
  } else if (coefficient > 0) {
    cout << "LEFT\n";
  } else {
    cout << "RIGHT\n";
  }
}

int main() {
  int t;

  cin >> t;

  while (t > 0) {
    long long x1, y1, x2, y2, x3, y3;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    get_point_location(x1, y1, x2, y2, x3, y3);

    t -= 1;
  }

  return 0;
}
