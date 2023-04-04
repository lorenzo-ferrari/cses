/*
Task:              2220 Counting Numbers
Sender:            lorenzo_ferrari
Submission time:   2022-05-20 14:30:24
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL solve(LL n) {
  // remember that 007 is a valid number!
  // solution: account only for numbers of length nn without leading 0s.
  // -> add solve(10**(nn-1) - 1) to the answer
  if (n <= 10) return n;
  string ss = to_string(n);
  for (char& c : ss) c -= '0';
  int nn = ss.size();
  // dp[i][0][j]: how many good not-tight suffixes [i:] starting in j
  // dp[i][1][j]: how many good tight suffixes [i:] starting in j
  // check https://codeforces.com/blog/entry/77096 for further explanations
  LL dp[20][2][10] {};
  for (int i = 0; i <= ss[nn-1]; ++i) dp[nn-1][0][i] = dp[nn-1][1][i] = 1;
  for (int i = ss[nn-1]+1; i <= 9; ++i) dp[nn-1][0][i] = 1;
  for (int i = nn-2; i >= 0; --i) {
    LL sum = 0;
    for (int j = 0; j <= 9; ++j) sum += dp[i+1][0][j];
    for (int j = 0; j <= 9; ++j) {
      dp[i][0][j] = sum - dp[i+1][0][j];
      if (j < ss[i]) {
        dp[i][1][j] = dp[i][0][j];
      } else if (j == ss[i]) {
        dp[i][1][j] = 0;
        for (int k = 0; k <= 9; ++k) {
          if (k != ss[i]) {
            dp[i][1][j] += dp[i+1][1][k];
          }
        }
      } else {
        dp[i][1][j] = 0;
      }
    }
  }
  LL ans = 0;
  for (int i = 1; i <= 9; ++i) ans += dp[0][1][i];
  LL m = 1;
  for (int i = 0; i < nn-1; ++i) m *= 10;
  m -= 1;
  return ans + solve(m);
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  LL a; cin >> a;
  LL b; cin >> b;
  cout << solve(b) - solve(a-1) << "\n";
}
