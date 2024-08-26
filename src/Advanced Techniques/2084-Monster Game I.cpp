#include "bits/stdc++.h"
using namespace std;
using LL = long long;

struct fn {
  LL m, q;
  explicit fn(LL _m, LL _q) : m(_m), q(_q) {}
  LL eval(LL x) const { return m*x + q; }
};

struct LCT_ZIP {
  int n;
  vector<fn> t;
  vector<LL> qs;
  vector<fn> history;
  explicit LCT_ZIP(vector<LL> _qs) : qs(_qs) {
    sort(begin(qs), end(qs));
    qs.resize(unique(begin(qs), end(qs)) - begin(qs));
    n = qs.size();
    t.assign(4 * n, fn(0, 1e15));
  }
  explicit LCT_ZIP(int _n) {
    vector<LL> q(_n);
    iota(begin(q), end(q), 0);
    *this = LCT_ZIP(q);
  }
  void add_fn(fn f) {
    history.push_back(f);
    if (!qs.empty()) add_fn(f, 1, 0, n);
  }
  void add_fn(fn f, int i, int l, int r) {
    int m = (l + r) / 2;
    bool lf = f.eval(qs[l]) < t[i].eval(qs[l]);
    bool md = f.eval(qs[m]) < t[i].eval(qs[m]);
    if (md) {
      swap(t[i], f);
    }
    if (r - l <= 1) return;
    if (lf != md) {
      add_fn(f, 2*i, l, m);
    } else {
      add_fn(f, 2*i+1, m, r);
    }
  }
  LL get(int x, int i = 1, int l = 0, int r = -1) {
    if (r == -1) r = n;
    int m = (l + r) / 2;
    if (r - l <= 1) return t[i].eval(x);
    if (x < qs[m]) {
      return min(t[i].eval(x), get(x, 2*i, l, m));
    } else {
      return min(t[i].eval(x), get(x, 2*i+1, m, r));
    }
  }
};

int main() {
	int n; cin >> n;
	int x; cin >> x;
	vector<LL> s(n + 1), f(n + 1);
	s[0] = 0, f[0] = x;
	for (int i = 1; i <= n; ++i) cin >> s[i];
	for (int i = 1; i <= n; ++i) cin >> f[i];
	LCT_ZIP lct(f);
	vector<LL> dp(n + 1);
	dp[n] = 0;
	lct.add_fn(fn(s[n], 0));
	for (int i = n - 1; i >= 0; --i) {
		dp[i] = lct.get(f[i]);
		lct.add_fn(fn(s[i], dp[i]));
	}
	cout << dp[0] << "\n";
}
