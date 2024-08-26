#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int mod = 1e9 + 7;

struct Matrix {
  int n;
  int m;
  vector<vector<LL>> a;
  Matrix(int _n, int _m = -1) : n(_n), m(_m) {
    if (m == -1) m = n;
    a.assign(n, vector<LL>(m, 0));
  }
  void make_unit() {
    assert(n == m);
    a.assign(n, vector<LL>(n, 0));
    for (int i = 0; i < n; ++i) {
      a[i][i] = 1;
    }
  }
  Matrix operator*(const Matrix other) const {
    assert(m == other.n);
    Matrix ans(n, other.m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < other.m; ++j) {
        for (int k = 0; k < m; ++k) {
          ans.a[i][j] += a[i][k] * other.a[k][j] % mod;
          ans.a[i][j] %= mod;
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

void print(Matrix m) {
  for (int i = 0; i < m.n; ++i) {
    for (int j = 0; j < m.m; ++j) {
      cout << m.a[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
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
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    ++adj.a[a][b];
  }
  Matrix ans = mat_exp(adj, k);
  cout << ans.a[0][n-1] << "\n";
}
