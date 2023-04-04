/*
Task:              2138 Reachable Nodes
Sender:            lorenzo_ferrari
Submission time:   2022-01-28 10:52:16
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
using LL = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int m; cin >> m;
  vector<vector<int>> g(n);
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
  }
  vector<int> o;
  vector<bool> vis(n);
  function<void(int)> dfs = [&](int v) {
    if (vis[v]) return;
    vis[v] = true;
    for (int u : g[v]) {
      dfs(u);
    }
    o.push_back(v);
  };
  for (int i = 0; i < n; ++i) {
    dfs(i);
  }
  // o is a reversed toposort
  // reverse(o.begin(), o.end());
  constexpr int N = 5e4;
  bitset<N> reach[N];
  for (int i = 0; i < n; ++i) reach[i][i] = 1;
  for (int v : o) {
    for (int u : g[v]) {
      reach[v] |= reach[u];
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << reach[i].count() << "\n";
  }
  cout << "\n";
}
