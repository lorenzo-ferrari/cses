#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL mod = 1e9 + 7;
const LL inf = 1e18;

pair<vector<LL>,vector<LL>> cnt_paths(int n, int src, vector<set<pair<LL,LL>>>& g) {
  vector<LL> d(n, inf);
  vector<LL> cnt(n, 0);
  priority_queue<pair<LL,LL>> Q;
  d[src] = 0, cnt[src] = 1;
  Q.push({0, src});
  while (!Q.empty()) {
    // d[v] and cnt[v] won't never be updated again
    LL td = -Q.top().first;
    LL v  =  Q.top().second;
    Q.pop();
    if (td > d[v]) continue;
    for (auto [u, w] : g[v]) {
      if (d[u] > td + w) {
        d[u] = td + w;
        cnt[u] = 0;
        Q.push({-d[u], u});
      }
      if (d[u] == td + w) cnt[u] = (cnt[u] + cnt[v]) % mod;
    }
  }
  return {d, cnt};
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;
  // fsr it doesn't work with duplicates edges (vector<vector<...>>)
  vector<set<pair<LL,LL>>> g(n);
  vector<set<pair<LL,LL>>> r(n);
  for (int i = 0, a, b, c; i < m; ++i) {
    cin >> a >> b >> c;
    --a, --b;
    g[a].insert({b, c});
    r[b].insert({a, c});
  }
  auto [d_s, cnt_s] = cnt_paths(n, 0, g);
  auto [d_e, cnt_e] = cnt_paths(n, n-1, r);
  assert(cnt_s[n-1] == cnt_e[0]);
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (d_s[i] + d_e[i] == d_s[n-1] &&
        cnt_s[i] * cnt_e[i] % mod == cnt_s[n-1]) {
      ans.push_back(i+1);
    }
  }
  cout << ans.size() << "\n";
  for (int i : ans) cout << i << " ";
  cout << "\n";
}

