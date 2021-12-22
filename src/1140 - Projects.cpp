#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n), b(n), p(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i] >> b[i] >> p[i];
  {
    vector<int> c = a;
    c.insert(c.end(), b.begin(), b.end());
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    for (int& i : a) i = lower_bound(c.begin(), c.end(), i) - c.begin();
    for (int& i : b) i = lower_bound(c.begin(), c.end(), i) - c.begin();
  }
  vector<long long> dp(2 * n + 1);
  vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int i, int j){return a[i] < a[j];});

  for (int i = 0, j = 0; i < 2 * n; ++i) {
    dp[i + 1] = max(dp[i], dp[i + 1]);
    for (; j < n && a[idx[j]] <= i; ++j)
      dp[b[idx[j]]+1] = max(dp[b[idx[j]]+1], dp[a[idx[j]]] + p[idx[j]]);
  }

  cout << dp.back() << "\n";
}

