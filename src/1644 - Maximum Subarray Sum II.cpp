#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MAXN = 1 << 18;

LL t[2 * MAXN];

void upd(int i, LL x) {
  for (t[i += MAXN] = x; i > 1; i >>= 1)
    t[i >> 1] = min(t[i], t[i^1]);
}

LL qry(int l, int r) {
  LL ans = 1e15;
  for (l += MAXN, r += MAXN; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = min(ans, t[l++]);
    if (r & 1) ans = min(ans, t[--r]);
  }
  return ans;
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, a, b;
  cin >> n >> a >> b;
  fill(t, t + 2 * MAXN, 1e15);
  vector<LL> v(n);
  for (LL& i : v) cin >> i;
  upd(0, 0);
  LL ans = -1e15;
  for (LL prf = 0, i = 0; i < n; ++i) {
    prf += v[i];
    ans = max(ans, prf - qry(max(0LL, i-b+1), i-a+2));
    upd(i + 1, prf);
  }
  cout << ans << "\n";
}

