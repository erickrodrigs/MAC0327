#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;

vector<double> get_triangle_sides(double x1, double y1, double x2, double y2, double x3, double y3) {
  // a = (x1, y1), b = (x2, y2), c = (x3, y3)
  double distance_ab = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  double distance_ac = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
  double distance_bc = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));

  return { distance_ab, distance_ac, distance_bc };
}

double get_triangle_perimeter(vector<double> & sides) {
  double a = sides[0];
  double b = sides[1];
  double c = sides[2];

  return a + b + c;
}

double get_triangle_area(vector<double> & sides) {
  // heron's formula to calculate area = sqrt(s * (s - a) * (s - b) * (s - c))
  double a = sides[0];
  double b = sides[1];
  double c = sides[2];
  double semiperimeter = (a + b + c) / 2;
  double area = sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));

  return area;
}

int main() {
  vector<double> triangle_sides;
  double x1, y1, x2, y2, x3, y3, perimeter, area;

  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  triangle_sides = get_triangle_sides(x1, y1, x2, y2, x3, y3);
  perimeter = get_triangle_perimeter(triangle_sides);
  area = get_triangle_area(triangle_sides);

  cout << fixed << setprecision(4) << perimeter << " " << area << "\n";

  return 0;
}
