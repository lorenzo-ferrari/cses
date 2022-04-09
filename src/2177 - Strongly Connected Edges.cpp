#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int m; cin >> m;
  vector<vector<int>> g(n);
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> lv(n, -1);
  vector<vector<int>> tree(n), be(n), fe(n);
  auto dfs = [&](auto&& self, int v, int p) -> void {
    for (int u : g[v]) {
      if (u == p) continue;
      if (lv[u] == -1) {
        tree[v].push_back(u);
        lv[u] = lv[v] + 1;
        self(self, u, v);
      } else if (lv[u] > lv[v]) {
        fe[v].push_back(u);
      } else {
        be[v].push_back(u);
      }
    }
  };
  lv[0] = 0;
  dfs(dfs, 0, -1);
  vector<int> dp(n);
  auto over = [&](auto&& self, int v) -> int {
    dp[v] = be[v].size() - fe[v].size();
    for (int u : tree[v]) {
      dp[v] += self(self, u);
    }
    return dp[v];
  };
  dp[0] = over(over, 0);
  for (int i = 1; i < n; ++i) {
    if (dp[i] == 0) {
      cout << "IMPOSSIBLE" << "\n";
      return 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j : tree[i]) {
      cout << i+1 << " " << j+1 << "\n";
    }
    for (int j : be[i]) {
      cout << i+1 << " " << j+1 << "\n";
    }
  }
}

