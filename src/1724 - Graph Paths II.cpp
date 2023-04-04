/*
Task:              1724 Graph Paths II
Sender:            lorenzo_ferrari
Submission time:   2022-02-15 12:23:16
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL INF = 1.8e18;

struct Matrix {
  int n;
  int m;
  vector<vector<LL>> a;
  Matrix(int _n, int _m = -1) : n(_n), m(_m) {
    if (m == -1) m = n;
    a.assign(n, vector<LL>(m, INF));
  }
  void make_unit() {
    assert(n == m);
    a.assign(n, vector<LL>(n, INF));
    for (int i = 0; i < n; ++i) {
      a[i][i] = 0;
    }
  }
  Matrix operator*(const Matrix other) const {
    assert(m == other.n);
    Matrix ans(n, other.m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < other.m; ++j) {
        for (int k = 0; k < m; ++k) {
          ans.a[i][j] = min(ans.a[i][j], a[i][k] + other.a[k][j]);
        }
      }
    }
    return ans;
  }
};
Matrix mat_exp(Matrix base, LL y) {
  assert(base.n == base.m);
  Matrix ans(base.n); ans.make_unit();
  while (y) {
    if (y & 1) ans = ans * base;
    y >>= 1;
    base = base * base;
  }
  return ans;
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int m; cin >> m;
  int k; cin >> k;
  Matrix adj(n);
  for (int i = 0, a, b, c; i < m; ++i) {
    cin >> a >> b >> c;
    --a, --b;
    adj.a[a][b] = min(adj.a[a][b], (LL)c);
  }
  Matrix ans = mat_exp(adj, k);
  cout << (ans.a[0][n-1] == INF ? -1LL : ans.a[0][n-1]) << "\n";
}
