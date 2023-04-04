/*
Task:              1139 Distinct Colors
Sender:            lorenzo_ferrari
Submission time:   2022-03-03 12:58:07
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  vector<vector<int>> adj(n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> ans(n);
  auto dfs = [&](auto&& self, int v, int p) -> set<int> {
    set<int> me;
    me.insert(c[v]);
    for (int u : adj[v]) {
      if (u == p) continue;
      auto child = self(self, u, v);
      if (child.size() > me.size()) swap(me, child);
      for (int i : child) me.insert(i);
    }
    ans[v] = me.size();
    return me;
  };
  dfs(dfs, 0, -1);
  for (int i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}
