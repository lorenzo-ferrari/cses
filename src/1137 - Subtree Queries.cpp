/*
Task:              1137 Subtree Queries
Sender:            lorenzo_ferrari
Submission time:   2022-03-03 15:06:03
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct Segment {
  int n;
  vector<LL> t;
  Segment(int _n) {
    for (n = 1; n < _n; n <<= 1);
    t.resize(2 * n);
  }
  void upd(int i, int nw) {
    for (t[i += n] = nw; i > 1; i >>= 1) {
      t[i >> 1] = t[i] + t[i ^ 1];
    }
  }
  LL qry(int l, int r) {
    LL ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans += t[l++];
      if (r & 1) ans += t[--r];
    }
    return ans;
  }
};

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int q; cin >> q;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  vector<vector<int>> adj(n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int t = 0;
  vector<int> tin(n);
  vector<int> tout(n);
  auto dfs = [&](auto&& self, int v, int p) -> void {
    tin[v] = t++;
    for (int u : adj[v]) {
      if (u == p) continue;
      self(self, u, v);
    }
    tout[v] = t;
  };
  dfs(dfs, 0, -1);
  Segment st(n);
  for (int i = 0; i < n; ++i) st.upd(tin[i], v[i]);
  for (int type, s, x; q--;) {
    cin >> type >> s; --s;
    if (type == 1) {
      cin >> x;
      st.upd(tin[s], x);
    } else {
      cout << st.qry(tin[s], tout[s]) << "\n";
    }
  }
}
