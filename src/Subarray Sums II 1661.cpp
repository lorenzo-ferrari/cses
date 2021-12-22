#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define _ << ' ' <<
#define F first
#define S second
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int x; cin >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  LL ans = 0;
  LL prf = 0;
  map<LL, int> cnt;
  for (int i = 0; i < n; ++i) {
    ++cnt[prf];
    prf += a[i];
    ans += cnt[prf - x];
  }
  cout << ans << "\n";
}

