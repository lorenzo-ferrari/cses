#include <bits/stdc++.h>
using namespace std;

struct Lca {
  const int L = 20;
  int n;
  vector<int> dep;
  vector<vector<int>> up;
  Lca(int _n, vector<int> p) : n(_n) {
    dep.assign(n, 0);
    up.assign(n, vector<int>(L, -1));
    for (int i = 0; i < n; ++i) up[i][0] = p[i];
    for (int i = 1; i < L; ++i) {
      for (int j = 0; j < n; ++j) {
        if (up[j][i-1] == -1) up[j][i] = -1;
        else up[j][i] = up[up[j][i-1]][i-1];
      }
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
      if (p[i] == -1) continue;
      adj[p[i]].push_back(i);
    }
    auto dfs = [&](auto&& self, int v, int p) -> void {
      for (int u : adj[v]) {
        if (u == p) continue;
        dep[u] = dep[v] + 1;
        self(self, u, v);
      }
    };
    dfs(dfs, 0, -1);
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
  int lca(int a, int b) {
    if (dep[a] > dep[b]) a = lift(a, dep[a] - dep[b]);
    if (dep[b] > dep[a]) b = lift(b, dep[b] - dep[a]);
    for (int i = L-1; i >= 0; --i) {
      if (up[a][i] != up[b][i]) {
        a = up[a][i];
        b = up[b][i];
      }
    }
    if (a == b) return a;
    return up[a][0];
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
  Lca lca(n, p);
  for (int i = 0, a, b; i < q; ++i) {
    cin >> a >> b; --a; --b;
    int ans = lca.lca(a, b) + 1;
    cout << ans << "\n";
  }
}

