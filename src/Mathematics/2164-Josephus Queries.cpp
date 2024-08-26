#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int query(int n, int k) {
  assert(k <= n);
  if (n == 1) return 1;
  if (k <= n / 2) return 2 * k;
  int t = query((n + 1) / 2, k - n / 2);
  if (n & 1) {
    if (t == 1) return n;
    return 2 * t - 3;
  } else {
    return 2 * t - 1;
  }
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int q; cin >> q;
  for (int n, k; q--;) {
    cin >> n >> k;
    cout << query(n, k) << "\n";
  }
}
