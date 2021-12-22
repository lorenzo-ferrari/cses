#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int k; cin >> k;
  vector<int> a(n);
  for(int& i : a) cin >> i;
  auto psb = [n,k,&a](ll x) {
    for (int i = 0, j = 0; i < k; ++i) {
      for (ll s = 0; j < n && s + a[j] <= x; s += a[j++]);
      if (j == n)
        return true;
    }
    return false;
  };
  ll l = 0, r = 200'000'000'000'000LL;
  while (r - l != 1) {
    ll m = l + (r - l) / 2;
    if (psb(m))
      r = m;
    else
      l = m;
  }
  cout << r << "\n";
}

