#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL mod = 1e9 + 7;
const LL N = 1e6;

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
  string s; cin >> s;
  int frq[26] {};
  for (char c : s) {
    ++frq[c - 'a'];
  }
  LL ans = f[s.size()];
  for (int i = 0; i < 26; ++i) {
    ans = ans * inv(f[frq[i]]) % mod;
  }
  cout << ans << "\n";
}

