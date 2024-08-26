#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL mod = 1e9 + 7;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  LL n; cin >> n;
  vector<LL> dis(n + 1);
  dis[0] = 1;
  dis[1] = 0;
  for (int i = 2; i <= n; ++i) {
    dis[i] = (i-1) * (dis[i-1] + dis[i-2]) % mod;
  }
  cout << dis[n] << "\n";
}
