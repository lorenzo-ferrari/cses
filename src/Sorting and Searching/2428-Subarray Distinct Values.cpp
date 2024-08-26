#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define _ << ' ' <<
#define F first
#define S second
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int k; cin >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  LL ans = 0;
  int cnt = 0;
  map<int, int> frq;
  for (int i = 0, j = -1; i < n; ++i) {
    cnt += ++frq[a[i]] == 1;
    while (cnt > k) {
      cnt -= --frq[a[++j]] == 0;
    }
    ans += i - j;
  }
  cout << ans << "\n";

}
