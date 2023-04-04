/*
Task:              1164 Room Allocation
Sender:            lorenzo_ferrari
Submission time:   2021-12-14 09:32:11
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<array<int, 3>> ex;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    ex.push_back({a[i], 0, i});
    ex.push_back({b[i], 1, i});
  }
  sort(ex.begin(), ex.end());
  vector<int> ans(n, -1);
  int cnt = 1;
  vector<int> fr(1, 1);
  for (auto [x, ty, id] : ex) {
    if (ty == 1) {
      fr.push_back(ans[id]);
    } else {
      if (fr.empty()) fr.push_back(++cnt);
      ans[id] = fr.back();
      fr.pop_back();
    }
  }
  cout << cnt << "\n";
  for (int i : ans)
    cout << i << " ";
  cout << "\n";
}
