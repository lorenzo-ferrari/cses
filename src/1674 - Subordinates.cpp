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
  for (int i = 1; i < n; ++i) {
    int p; cin >> p;
    adj[p-1].push_back(i);
  }
  vector<int> mem(n);
  function<int(int)> dfs = [&](int v) {
    int ans = adj[v].size();
    for (int u : adj[v])
      ans += dfs(u);
    return mem[v] = ans;
  };
  dfs(0);
  for (int i = 0; i < n; ++i) {
    cout << mem[i] << " ";
  }
  cout << "\n";
}

