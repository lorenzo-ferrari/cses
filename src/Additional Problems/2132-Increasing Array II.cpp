// https://codeforces.com/blog/entry/77298
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  LL ans = 0;
  int n; cin >> n;
  priority_queue<int> Q;
  for (int i = 0, t; i < n; ++i) {
    cin >> t;
    Q.push(t);
    Q.push(t);
    ans += Q.top() - t;
    Q.pop();
  }
  cout << ans << "\n";
}
