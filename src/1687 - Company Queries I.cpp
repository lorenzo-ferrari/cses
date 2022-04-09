#include <bits/stdc++.h>
using namespace std;

struct Lift {
  const int L = 20;
  int n;
  vector<vector<int>> up;
  Lift(int _n, vector<int> p) : n(_n) {
    up.assign(n, vector<int>(L, -1));
    for (int i = 0; i < n; ++i) up[i][0] = p[i];
    for (int i = 1; i < L; ++i) {
      for (int j = 0; j < n; ++j) {
        if (up[j][i-1] == -1) up[j][i] = -1;
        else up[j][i] = up[up[j][i-1]][i-1];
      }
    }
  }
  int lift(int v, int k) {
    for (int i = L-1; v != -1 && i >= 0; --i) {
      if (k >= (1 << i)) {
        v = up[v][i];
        k -= 1 << i;
      }
    }
    return v;
  }
};

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int q; cin >> q;
  vector<int> p(n, -1);
  for (int i = 1; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  Lift lift(n, p);
  for (int i = 0, v, k; i < q; ++i) {
    cin >> v >> k; --v;
    int ans = lift.lift(v, k);
    if (ans != -1) ++ans;
    cout << ans << "\n";
  }
}

