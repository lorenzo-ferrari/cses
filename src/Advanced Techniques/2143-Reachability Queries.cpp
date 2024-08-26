#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
using LL = long long;

struct Scc {
  int n;
  vector<int> belong;
  vector<vector<int>> g;
  vector<vector<int>> components;
  Scc(vector<vector<int>> _g) : g(_g) {
    n = g.size();
    vector<int> o;
    vector<bool> vis(n);
    function<void(int)> dfs1 = [&](int v) {
      if (vis[v]) return;
      vis[v] = true;
      for (int u : g[v]) {
        dfs1(u);
      }
      o.push_back(v);
    };
    for (int i = 0; i < n; ++i) dfs1(i);
    reverse(o.begin(), o.end());
    vector<vector<int>> gt(n);
    for (int i = 0; i < n; ++i) {
      for (int j : g[i]) {
        gt[j].push_back(i);
      }
    }
    function<void(int)> dfs2 = [&](int v) {
      if (vis[v]) return;
      vis[v] = true;
      for (int u : gt[v]) {
        dfs2(u);
      }
      belong[v] = components.size() - 1;
      components.back().push_back(v);
    };
    vis.assign(n, false);
    belong.resize(n, -1);
    for (int i : o) {
      if (!vis[i]) {
        components.push_back(vector<int>(0));
        dfs2(i);
      }
    }
  }
  auto get_condensation_graph() {
    vector<vector<int>> cg(components.size());
    for (int i = 0; i < n; ++i) {
      for (int j : g[i]) {
        if (belong[i] != belong[j]) {
          cg[belong[i]].push_back(belong[j]);
        }
      }
    }
    return cg;
  }
  int operator[](int i){ return belong[i]; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int m; cin >> m;
  int q; cin >> q;
  vector<vector<int>> g(n);
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
  }
  Scc scc(g);
  auto cg = scc.get_condensation_graph();
  int nn = scc.components.size();
  vector<int> o;
  vector<bool> vis(nn);
  function<void(int)> dfs = [&](int v) {
    if (vis[v]) return;
    vis[v] = true;
    for (int u : cg[v]) {
      dfs(u);
    }
    o.push_back(v);
  };
  for (int i = 0; i < nn; ++i) {
    dfs(i);
  }

#ifdef LORENZO
  constexpr int N = 42;
#else
  constexpr int N = 50000;
#endif
  bitset<N> reach[N];
  for (int i = 0; i < n; ++i) reach[i][i] = 1;
  for (int i : o) {
    for (int j : cg[i]) {
      reach[i] |= reach[j];
    }
  }
  for (int i = 0, a, b; i < q; ++i) {
    cin >> a >> b;
    --a, --b;
    if (reach[scc[a]][scc[b]]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
