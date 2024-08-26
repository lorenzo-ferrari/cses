#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int x; cin >> x;
  int n; cin >> n;
  priority_queue<LL, vector<LL>, greater<LL>> Q;
  for (int i = 0; i < n; ++i) {
    int d; cin >> d;
    Q.push(d);
  }
  LL ans = 0;
  while (Q.size() >= 2) {
    LL a = Q.top(); Q.pop();
    LL b = Q.top(); Q.pop();
    ans += a + b;
    Q.push(a + b);
  }
  cout << ans << "\n";
}
