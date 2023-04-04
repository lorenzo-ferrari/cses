/*
Task:              1130 Tree Matching
Sender:            lorenzo_ferrari
Submission time:   2022-01-10 21:33:09
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 1, a, b; i < n; ++i) {
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> inc(n), ign(n);
  function<void(int, int)> dfs = [&](int v, int p) {
    int d = -1;
    for (int u : adj[v]) {
      if (u == p) continue;
      dfs(u, v);
      ign[v] += inc[u];
      d = max(d, ign[u] - inc[u]);
    }
    inc[v] = ign[v] + d + 1;
  };
  dfs(0, -1);
  cout << inc[0] << "\n";
}
