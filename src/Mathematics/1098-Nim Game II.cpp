#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int xr = 0;
    for (int i = 0; i < n; ++i) {
      int a; cin >> a;
      xr ^= a % 4;
    }
    cout << (xr != 0 ? "first" : "second") << "\n";
  }
}
