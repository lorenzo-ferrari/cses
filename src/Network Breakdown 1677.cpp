#include <bits/stdc++.h>
using namespace std;

struct Dsu {
  vector<int> p;

  Dsu(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  int findset(int v) {
    return p[v] == v ? v : p[v] = findset(p[v]);
  }

  bool unionset(int a, int b) {
    a = findset(a);
    b = findset(b);
    if (a == b) return false;
    p[b] = a;
    return true;
  }
};

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int m; cin >> m;
  int k; cin >> k;
  vector<array<int, 2>> e(m);
  vector<map<int, int>> idx(n + 1);
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    e[i] = {a, b};
    idx[a][b] = idx[b][a] = i;
  }
  vector<bool> stay(m, true);
  vector<array<int, 2>> qry(k);
  for (int i = 0, a, b; i < k; ++i) {
    cin >> a >> b;
    stay[idx[a][b]] = false;
    qry[i] = {a, b};
  }
  reverse(qry.begin(), qry.end());
  Dsu dsu(n + 1);
  int cnt = n;
  for (int i = 0; i < m; ++i) {
    if (stay[i]) {
      cnt -= dsu.unionset(e[i][0], e[i][1]);
    }
  }
  vector<int> ans(k);
  for (int i = 0; i < k; ++i) {
    ans[i] = cnt;
    cnt -= dsu.unionset(qry[i][0], qry[i][1]);
  }
  reverse(ans.begin(), ans.end());
  for (int i : ans)
    cout << i << " ";
  cout << "\n";
}

