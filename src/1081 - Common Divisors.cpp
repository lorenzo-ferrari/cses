/*
Task:              1081 Common Divisors
Sender:            lorenzo_ferrari
Submission time:   2021-12-01 14:53:42
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int ans = 1;
  bitset<1<<20> v(0);
  for (int x; cin >> x;) {
    for (int i = 1; i*i <= x; ++i) {
      if (x % i) continue;
      if (v[i  ]) ans = max(ans, i  );
      if (v[x/i]) ans = max(ans, x/i);
      v[i  ] = 1;
      v[x/i] = 1;
    }
  }
  cout << ans << "\n";
}
