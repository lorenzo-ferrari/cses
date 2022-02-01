#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL mod = 1e9 + 7;
const LL N = 2e6;

LL fexp(LL x, LL y) {
  LL ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
LL inv(LL x) { return fexp(x, mod - 2); }

LL f[N + 1];

int main() {
  f[0] = 1;
  for (int i = 1; i <= N; ++i) {
    f[i] = f[i - 1] * i % mod;
  }
  int n; cin >> n;
  int m; cin >> m;
  LL ans = f[n-1+m];
  ans = ans * inv(f[n-1]) % mod;
  ans = ans * inv(f[m]) % mod;

  cout << ans << "\n";
}

