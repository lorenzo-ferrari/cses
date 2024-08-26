#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  LL n; cin >> n;
  LL k; cin >> k;
  vector<LL> p(k);
  for (int i = 0; i < k; ++i) {
    cin >> p[i];
  }
  LL ans = 0;
  for (int mask = 1; mask < (1 << k); ++mask) {
    LL f = 1;
    int sgn = 0;
    for (int i = 0; i < k; ++i) {
      if (mask & (1 << i)) {
        sgn ^= 1;
        f = (f > (n + p[i] - 1) / p[i]) ? n+1 : f * p[i];
      }
    }
    if (sgn) ans += n / f;
    else ans -= n / f;
  }
  cout << ans << "\n";
}
