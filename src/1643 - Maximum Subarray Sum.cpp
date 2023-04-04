/*
Task:              1643 Maximum Subarray Sum
Sender:            lorenzo_ferrari
Submission time:   2023-02-15 17:28:41
Language:          C++17
Result:            ACCEPTED
*/
// https://cses.fi/problemset/task/1643
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  LL ans = -1e9;
  LL prf = 0;
  LL minPrf = 0;
  for (int i = 0; i < n; ++i) {
    prf += a[i];
    ans = max(ans, prf - minPrf);
    minPrf = min(prf, minPrf);
  }
  cout << ans << "\n";
}
