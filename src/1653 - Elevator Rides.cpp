/*
Task:              1653 Elevator Rides
Sender:            lorenzo_ferrari
Submission time:   2021-12-22 15:31:50
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int x; cin >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<array<int, 2>> dp(1 << n);
  dp[0] = {0, x};
  for (int mask = 1; mask < (1 << n); ++mask) {
    dp[mask] = {n, x};
    for (int i = 0; i < n; ++i) {
      if (!(mask & (1 << i))) continue;
      auto [c, w] = dp[mask ^ (1 << i)];
      if (w + a[i] <= x)
        dp[mask] = min(dp[mask], {c, w + a[i]});
      else
        dp[mask] = min(dp[mask], {c + 1, a[i]});
    }
  }
  cout << dp[(1 << n) - 1][0] << "\n";
}
