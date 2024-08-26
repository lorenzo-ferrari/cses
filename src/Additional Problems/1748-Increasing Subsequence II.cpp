#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL mod = 1e9 + 7;

struct Fenwick {
  // implementation 1-based
  // handles queries/adds 0-based
  int n;
  vector<LL> t;
  Fenwick(int n) : n(n) {
    t.assign(n + 1, 0);
  }
  void add(int i, int x) {
    assert(i <= n);
    for (++i; i <= n; i += (i & -i)) {
      t[i] += x;
    }
  }
  LL sum(int r) {
    LL ans = 0;
    for (++r; r > 0; r -= r & -r) {
      ans += t[r];
    }
    return ans;
  }
  LL sum(int l, int r) {
    return sum(r) - sum(l-1);
  }
};

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  {
    auto z = a;
    sort(z.begin(), z.end());
    z.resize(unique(z.begin(), z.end()) - z.begin());
    for (int& i : a) {
      i = lower_bound(z.begin(), z.end(), i) - z.begin();
    }
  }
  vector<LL> dp(n);
  Fenwick ft(n+1); ft.add(n, 1);
  for (int i = n-1; i >= 0; --i) {
    dp[i] = ft.sum(a[i]+1, n);
    dp[i] %= mod;
    ft.add(a[i], dp[i]);
  }
  LL sum = 0;
  for (LL& x : dp) {
    sum = (sum + x) % mod;
  }
  cout << sum << "\n";
}
