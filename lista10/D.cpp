#include <iostream>
#include <vector>
using namespace std;

long long calculate_polygon_area_times_two(vector<pair<long long, long long>> & vertices, int n) {
  long long first_product = 1;
  long long second_product = 1;

  for (int i = 1; i < n; i++) {
    const pair<long long, long long> & previous_vertex = vertices.at(i - 1);
    const pair<long long, long long> & current_vertex = vertices.at(i);
    long long previous_x = previous_vertex.first;
    long long previous_y = previous_vertex.second;
    long long current_x = current_vertex.first;
    long long current_y = current_vertex.second;

    first_product += (previous_x * current_y);
    second_product += (current_x * previous_y);
  }

  return abs(first_product - second_product);
}

int main() {
  vector<pair<long long, long long>> vertices;
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;

    vertices.push_back({ x, y });
  }

  vertices.push_back(vertices.at(0));

  cout << calculate_polygon_area_times_two(vertices, n + 1) << "\n";

  return 0;
}
