/*
Task:              2079 Finding a Centroid
Sender:            lorenzo_ferrari
Submission time:   2022-05-21 12:56:30
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

struct CentroidDecomposition {
  int root;
  vector<int> par;
  vector<int> sz;
  vector<bool> cen;
  vector<vector<int>> adj;

  CentroidDecomposition(const vector<vector<int>>& adj) : adj(adj) {
    int n = adj.size();
    par.assign(n, -1);
    sz.assign(n, 0);
    cen.assign(n, false);
    root = decompose(0, -1);
  }

  int dfs(int v, int p) {
    sz[v] = 1;
    for (int u : adj[v]) {
      if (u == p || cen[u]) continue;
      sz[v] += dfs(u, v);
    }
    return sz[v];
  }

  int centroid(int v, int p, const int size) {
    for (int u : adj[v]) {
      if (u == p || cen[u]) continue;
      if (sz[u] > size / 2) {
        return centroid(u, v, size);
      }
    }
    return v;
  }

  int decompose(int v, int p) {
    int n = dfs(v, p);
    int c = centroid(v, p, n);
    cen[c] = true;
    if (p == -1) {
      root = p = c;
    }
    par[c] = p;
    for (int u : adj[c]) {
      if (!cen[u]) {
        decompose(u, c);
      }
    }
    return c;
  }

  int operator[](int i){ return par[i]; }
};

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#endif
  int n; cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    cin >> a >> b; --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  CentroidDecomposition cd(adj);
  cout << cd.root+1 << "\n";
}
