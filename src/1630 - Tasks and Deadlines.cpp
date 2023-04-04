/*
Task:              1630 Tasks and Deadlines
Sender:            lorenzo_ferrari
Submission time:   2021-12-14 13:25:08
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vector<array<int, 2>> t(n);
  for (auto& [a, d] : t)
    cin >> a >> d;
  sort(t.begin(), t.end());
  LL ans = 0, prf = 0;
  for (auto [a, d] : t) {
    prf += a;
    ans += d - prf;
  }
  cout << ans << "\n";
}
