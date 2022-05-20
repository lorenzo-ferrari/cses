#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int t; cin >> t;
  vector<int> v(n);
  for (int& i : v) cin >> i;
  int a = n / 2;
  int b = n - a;
  vector<int> va, vb;
  for (int i = 0; i < (1 << a); ++i) {
    LL sum = 0;
    for (int j = 0; j < a; ++j) {
      if (i & (1 << j)) {
        sum += v[j];
      }
    }
    if (sum <= t) va.push_back(sum);
  }
  for (int i = 0; i < (1 << b); ++i) {
    LL sum = 0;
    for (int j = 0; j < b; ++j) {
      if (i & (1 << j)) {
        sum += v[j + a];
      }
    }
    if (sum <= t) vb.push_back(sum);
  }
  sort(begin(va), end(va));
  sort(begin(vb), end(vb));
  vector<array<int, 2>> vv;
  for (int i : va) {
    if (vv.empty() || vv.back()[0] != i) {
      vv.push_back({i, 1});
    } else {
      ++vv.back()[1];
    }
  }
  LL ans = 0;
  for (int i = 0, j = vv.size()-1; i < int(vb.size()); ++i) {
    while (j > 0 && vv[j][0] + vb[i] > t) --j;
    if (vv[j][0] + vb[i] == t) {
      ans += vv[j][1];
    }
  }
  cout << ans << "\n";
}

