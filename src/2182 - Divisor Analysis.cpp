#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL fexp(LL x, LL y, LL mod) {
  LL ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
LL inv(LL x, LL mod) { return fexp(x, mod - 2, mod); }

const LL mod = 1e9 + 7;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vector<LL> p(n), k(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i] >> k[i];
  }
  {
    LL cnt = 1;
    for (LL i : k) {
      cnt = cnt * (i+1) % mod;
    }
    cout << cnt << " ";
  }
  {
    LL sum = 1;
    for (int i = 0; i < n; ++i) {
      LL pp = (fexp(p[i], k[i]+1, mod) - 1 + mod) * inv(p[i] - 1, mod) % mod;
      sum = sum * pp % mod;
    }
    cout << sum << " ";
  }
  {
    const LL phi = mod - 1;
    vector<LL> prf(n+1); prf[0] = 1;
    vector<LL> sff(n+1); sff[n] = 1;
    for (int i = 0; i < n; ++i) prf[i+1] = prf[i] * (k[i]+1) % phi;
    for (int i = n-1; i > 0; --i) sff[i] = sff[i+1] * (k[i]+1) % phi;

    LL prd = 1;
    for (int i = 0; i < n; ++i) {
      LL e = k[i] * (k[i]+1) / 2; e %= phi;
      e = e * prf[i] % phi;
      e = e * sff[i+1] % phi;
      LL pp = fexp(p[i], e, mod);
      prd = prd * pp % mod;
    }
    cout << prd << "\n";
  }
}

