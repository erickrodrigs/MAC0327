#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> & repr, int a) {
  if (a == repr[a]) return a;

  repr[a] = find(repr, repr[a]);

  return repr[a];
}

void join(vector<int> & repr, vector<int> & size, int a, int b) {
  a = find(repr, a);
  b = find(repr, b);

  if (a == b) return;

  if (size[a] < size[b]) {
    repr[a] = b;
    size[b] += size[a];
  } else {
    repr[b] = a;
    size[a] += size[b];
  }
}

bool same_set(vector<int> & repr, int a, int b) {
  return find(repr, a) == find(repr, b);
}

int main() {
  vector<int> repr, size;
  int N, Q;

  ios::sync_with_stdio(false); cin.tie(nullptr);

  cin >> N >> Q;

  for (int i = 0; i < N; i++) {
    repr.push_back(i);
    size.push_back(1);
  }

  while (Q > 0) {
    int type, u, v;

    cin >> type >> u >> v;

    if (type == 0) {
      join(repr, size, u, v);
    } else {
      if (same_set(repr, u, v)) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }

    Q -= 1;
  }

  return 0;
}
