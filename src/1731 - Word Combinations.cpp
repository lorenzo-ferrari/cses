#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr LL N = 5005;
constexpr LL P = 29;
constexpr LL mod1 = 1e9 + 7;
constexpr LL mod2 = 1e9 + 9;

LL pp[N][2];
LL inv[N][2];

bitset<mod1> sh1;
bitset<mod2> sh2;

LL fxp(LL a, LL b, LL mod) {
  LL ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}
LL finv(LL a, LL mod) { return fxp(a, mod - 2, mod); }

void init() {
  pp[0][0] = inv[0][0] = 1;
  pp[0][1] = inv[0][1] = 1;
  for (int i = 0; i < N - 1; ++i) {
    pp[i+1][0] = pp[i][0] * P % mod1;
    pp[i+1][1] = pp[i][1] * P % mod2;
    inv[i+1][0] = finv(pp[i+1][0], mod1);
    inv[i+1][1] = finv(pp[i+1][1], mod2);
  }
}

struct Hash {
  int n, w;
  LL mod;
  vector<LL> prf;
  Hash(string s, LL mod, int w) : n(s.size()), w(w), mod(mod) {
    prf.resize(n+1);
    for (int i = 0; i < n; ++i) {
      prf[i+1] = prf[i] + (s[i] - 'a' + 1) * pp[i][w];
      prf[i+1] %= mod;
    }
  }
  LL gethash(int l = -1, int sz = -1) {
    if (sz == -1) sz = n;
    if (l == -1) return prf[sz];
    return (prf[l+sz] - prf[l] + mod) % mod * inv[l][w] % mod;
  }
};

int main() {
  init();
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s; cin >> s;
  int n = s.size();
  int m; cin >> m;
  for (int i = 0; i < m; ++i) {
    string x; cin >> x;
    sh1[Hash(x, mod1, 0).gethash()] = 1;
    sh2[Hash(x, mod2, 1).gethash()] = 1;
  }
  Hash h1(s, mod1, 0);
  Hash h2(s, mod2, 1);
  vector<LL> dp(n+1); dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      if (sh1[h1.gethash(i - j, j)] && sh2[h2.gethash(i - j, j)]) {
        dp[i] += dp[i - j];
        dp[i] %= mod1;
      }
    }
  }
  cout << dp[n] << "\n";
}

