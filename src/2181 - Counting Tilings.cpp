/*
Task:              2181 Counting Tilings
Sender:            lorenzo_ferrari
Submission time:   2022-05-20 18:28:52
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL mod = 1e9 + 7;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int m; cin >> m;
  auto inv = [n](int mask) -> int {
    return ~mask & ((1 << n) - 1);
  };
  auto good_start = [n](int mask) -> bool {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) ++cnt;
      else {
        if (cnt & 1) return false;
        cnt = 0;
      }
    }
    return (cnt & 1) == 0;
  };
  // dp[i][mask]: the first i (up to the (i-1)-th) rows are full
  // mask is left in the next row
  vector<vector<LL>> dp(m+1, vector<LL>(1 << n));
  for (int mask = 0; mask < (1 << n); ++mask) dp[0][mask] = good_start(mask);
  for (int i = 0; i < m; ++i) {
    // tt[i][mask]: l'ultimo [ ] e' stato aggiungo in [i-1,i]
    vector<vector<LL>> tt(n+1, vector<LL>(1 << n));
    for (int mask = 0; mask < (1 << n); ++mask) {
      tt[0][mask] = dp[i][inv(mask)];
      tt[0][mask] %= mod;
      for (int j = -1; j < n; ++j) {
        for (int k = j+2; k < n; ++k) {
          if (!(mask & (3 << (k-1)))) {
            tt[k+1][mask | (3 << (k-1))] += tt[j+1][mask];
            tt[k+1][mask | (3 << (k-1))] %= mod;
          }
        }
      }
      for (int j = 0; j <= n; ++j) dp[i+1][mask] += tt[j][mask];
      dp[i+1][mask] %= mod;
    }
  }
  cout << dp[m][0] << "\n";
}
