/*
Task:              1641 Sum of Three Values
Sender:            lorenzo_ferrari
Submission time:   2021-12-14 13:52:15
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  int n; cin >> n;
  int x; cin >> x;
  vector<array<int, 2>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i][0];
    a[i][1] = i + 1;
  }
  sort(a.begin(), a.end());
  function<pair<int,int>(int,int,int)> find = [&](int l, int r, int target) {
    pair<int,int> ans = {-1, -1};
    for (int i = l, j = r; i < j;) {
      int cur = a[i][0] + a[j][0];
      if (cur == target) {
        ans = {a[i][1], a[j][1]};
        return ans;
      }
      if (cur > target) --j;
      if (cur < target) ++i;
    }
    return ans;
  };
  for (int i = 0; i < n; ++i) {
    auto ans = find(i+1, n-1, x - a[i][0]);
    if (ans.first != -1) {
      cout << a[i][1] << " " << ans.first << " " << ans.second << "\n";
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << "\n";
}
