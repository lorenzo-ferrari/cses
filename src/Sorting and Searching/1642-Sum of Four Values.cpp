#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define _ << ' ' <<
#define F first
#define S second

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
  map<int, array<int, 2>> mp;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      int s = a[i] + a[j];
      if (mp.find(s) == mp.end()) {
        mp[s] = {j, i};
      }
      auto it = mp.find(x - s);
      if (it != mp.end() && it->S[1] < j) {
        cout << it->S[0]+1 _ it->S[1]+1 _ j+1 _ i+1 << "\n";
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << "\n";
}
