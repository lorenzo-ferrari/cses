#include <bits/stdc++.h>
using namespace std;
using LL = long long;

array<int, 2> best;

vector<vector<int>> adj;

void dfs(int v, int p, vector<int>& d) {
  best = max(best, {d[v], v});
  for (int u : adj[v]) {
    if (u == p) continue;
    d[u] = d[v] + 1;
    dfs(u, v, d);
  }
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  adj.resize(n);
  for (int i = 1, a, b; i < n; ++i) {
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> d0(n);
  dfs(0, -1, d0);
  int a = best[1];
  vector<int> da(n);
  best = {0, 0};
  dfs(a, -1, da);
  int b = best[1];
  vector<int> db(n);
  dfs(b, -1, db);

  for (int i = 0; i < n; ++i) {
    cout << max(da[i], db[i]) << " ";
  }
  cout << "\n";
}

