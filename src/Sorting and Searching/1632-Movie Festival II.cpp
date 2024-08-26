#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int k; cin >> k;
  vector<pair<int, int>> movies(n);
  for (auto& [a, b] : movies) {
    cin >> a >> b;
  }
  sort(movies.begin(), movies.end(), [](pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
  });
  multiset<int> fr;
  for (int i = 0; i < k; ++i) {
    fr.insert(0);
  }
  int ans = 0;
  for (auto [a, b] : movies) {
    auto it = fr.upper_bound(a);
    if (it != fr.begin()) {
      fr.erase(--it);
      ++ans;
      fr.insert(b);
    }
  }
  cout << ans << "\n";
}
