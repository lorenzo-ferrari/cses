// https://cses.fi/problemset/task/1202/

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

static constexpr LL mod = 1e9 + 7;

int main() {
  int n; cin >> n;
  int m; cin >> m;
  vector<vector<array<int, 2>>> adj(n);
  for (int i = 0, a, b, c; i < m; ++i) {
    cin >> a >> b >> c; --a, --b,
      adj[a].push_back({b, c});
  }
  vector<LL> d(n, 1e15);
  vector<LL> cnt(n, 0);
  vector<int> mn(n);
  vector<int> mx(n);
  d[0] = 0;
  cnt[0] = 1;
  priority_queue<array<LL, 2>> Q;
  Q.push({0, 0});
  while (!Q.empty()) {
    int v = Q.top()[1];
    LL td =-Q.top()[0];
    Q.pop();
    if (td > d[v]) {
      continue;
    }
    for (auto [u, w] : adj[v]) {
      if (d[u] > d[v] + w) {
        d[u] = d[v] + w;
        cnt[u] = cnt[v];
        mn[u] = mn[v] + 1;
        mx[u] = mx[v] + 1;
        Q.push({-d[u], u});
      } else if (d[u] == d[v] + w) {
        cnt[u] += cnt[v];
        cnt[u] %= mod;
        mn[u] = min(mn[u], mn[v] + 1);
        mx[u] = max(mx[u], mx[v] + 1);
      }
    }
  }
  cout << d[n-1] << " " << cnt[n-1] << " " << mn[n-1] << " " << mx[n-1] << "\n";
}

