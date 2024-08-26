#include <bits/stdc++.h>
using namespace std;
using LL = long long;

#define SQ(x) (x)*(x)
#define GAUSS(x) ((x)*(x+1)/2)

const LL mod = 1e9 + 7;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  LL n; cin >> n;
  LL ans = 0;
  for (__int128_t i = 1, o; i <= n; i += o + 1) {
    o = (n % i) / (n / i);
    o = min(o, n-i);
    ans = (ans + (n / i) % mod * (GAUSS(i+o) - GAUSS(i-1))) % mod; // n/i * sum(i...i+o)
  }
  cout << ans << "\n";
}
