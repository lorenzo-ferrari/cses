#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define F first
#define S second

vector<int> p;
vector<int> sz;
vector<pair<int, int>> history;

int findset(int v) {
  return p[v] == v ? v : findset(p[v]);
}

bool unionset(int a, int b) {
  a = findset(a);
  b = findset(b);
  if (a == b) return false;
  if (sz[a] < sz[b]) swap(a, b);
  p[b] = a;
  sz[a] += sz[b];
  history.push_back({a, b});
  return true;
}

void rollback() {
  auto [a, b] = history.back();
  history.pop_back();
  assert(p[b] == a);
  p[b] = b;
  sz[a] -= sz[b];
}

vector<int> ans;
vector<int> a, b;
vector<int> qa, qb;

void solve(int l, int r, vector<int>& v) {
  // [l, r)
  // ci sono solo gli archi con id < l
  if (r - l == 1) {
    for (int i : v)
      ans[i] = l;
    return;
  }
  if (l >= r) return;
  int m = (l + r) / 2;
  int cnt = 0;
  for (int i = l; i < m; ++i)
    cnt += unionset(a[i], b[i]);
  vector<int> low, high;
  for (int i : v) {
    if (findset(qa[i]) == findset(qb[i]))
      low.push_back(i);
    else
      high.push_back(i);
  }
  v.clear();
  solve(m, r, high);
  while (cnt--)
    rollback();
  solve(l, m, low);
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int m; cin >> m;
  int q; cin >> q;
  a.resize(m);
  b.resize(m);
  p.resize(n + 1);
  sz.resize(n + 1);
  for (int i = 1; i <= n; ++i)
    p[i] = i, sz[i] = 1;
  for (int i = 0; i < m; ++i)
    cin >> a[i] >> b[i];
  qa.resize(q);
  qb.resize(q);
  ans.resize(q, -1);
  for (int i = 0; i < q; ++i)
    cin >> qa[i] >> qb[i];
  vector<int> v(q);
  iota(v.begin(), v.end(), 0);
  solve(0, m + 1, v);
  for (int& i : ans) ++i;
  for (int i = 0; i < m; ++i) {
    unionset(a[i], b[i]);
  }
  for (int i = 0; i < q; ++i)
    if (findset(qa[i]) != findset(qb[i]))
      ans[i] = -1;
  for (int i = 0; i < q; ++i) {
    if (qa[i] == qb[i])
      ans[i] = 0;
  }
  for (int& i : ans)
    cout << i << "\n";
}

