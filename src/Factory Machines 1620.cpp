#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int t; cin >> t;
  vector<int> k(n);
  for (int& i : k) cin >> i;
  auto works = [&](__int128_t tm) {
    __int128_t cnt = 0;
    for (int i : k)
      cnt += tm / i;
    return cnt >= t;
  };
  __int128_t l = 0, r = 1e18;
  while (r - l > 1) {
    __int128_t m = (l + r) / 2;
    if (works(m))
      r = m;
    else
      l = m;
  }
  cout << LL(r) << "\n";
}

