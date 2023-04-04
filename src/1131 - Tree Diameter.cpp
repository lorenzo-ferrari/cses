/*
Task:              1131 Tree Diameter
Sender:            lorenzo_ferrari
Submission time:   2022-01-10 21:36:44
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

array<int, 2> best;

vector<int> d;
vector<vector<int>> adj;

void dfs(int v, int p) {
  best = max(best, {d[v], v});
  for (int u : adj[v]) {
    if (u == p) continue;
    d[u] = d[v] + 1;
    dfs(u, v);
  }
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  adj.resize(n);
  d.resize(n);
  for (int i = 1, a, b; i < n; ++i) {
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0, -1);
  int a = best[1];
  fill(d.begin(), d.end(), 0);
  dfs(a, -1);
  cout << best[0] << "\n";
}
