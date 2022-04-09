#include <bits/stdc++.h>
using namespace std;

struct Lca {
  const int L = 20;
  int n;
  vector<int> dep;
  vector<vector<int>> up;
  Lca(int _n, const vector<vector<int>>& _adj) : n(_n) {
    dep.assign(n, 0);
    up.assign(n, vector<int>(L, -1));
    dfs(0, -1, _adj);
    for (int i = 1; i < L; ++i) {
      for (int j = 0; j < n; ++j) {
        if (up[j][i-1] == -1) up[j][i] = -1;
        else up[j][i] = up[up[j][i-1]][i-1];
      }
    }
  }
  void dfs(int v, int pv, const vector<vector<int>>& adj) {
    for (int u : adj[v]) {
      if (u == pv) continue;
      dep[u] = dep[v] + 1;
      up[u][0] = v;
      dfs(u, v, adj);
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
  int dist(int a, int b) {
    int l = lca(a, b);
    return dep[a] + dep[b] - 2*dep[l];
  }
};

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int m; cin >> m;
  vector<vector<int>> adj(n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    cin >> a >> b; --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  Lca lca(n, adj);
  vector<int> am_lca(n);
  vector<int> cnt_co(n);
  vector<int> cnt_nd(n);
  vector<array<int, 2>> paths(m);
  for (auto& [a, b] : paths) {
    cin >> a >> b; --a; --b;
    ++cnt_nd[a];
    ++cnt_nd[b];
    int l = lca.lca(a, b);
    ++am_lca[l];
    ++cnt_co[l];
  }
  vector<int> ans(n);
  auto dfs = [&](auto&& self, int v, int p) -> void {
    for (int u : adj[v]) {
      if (u == p) continue;
      self(self, u, v);
      cnt_co[v] += cnt_co[u];
      cnt_nd[v] += cnt_nd[u];
    }
    ans[v] = cnt_nd[v] - 2*cnt_co[v] + am_lca[v];
  };
  dfs(dfs, 0, -1);
  for (int i : ans) cout << i << " ";
  cout << "\n";
}

