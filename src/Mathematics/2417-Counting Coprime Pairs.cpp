#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e6;

int u[N + 1], d[N + 1];
vector<int> pr;

void sieve() {
  u[1] = 1; // definition
  for (int i = 2; i <= N; ++i) {
    if (d[i] == 0) {
      u[i] = -1;
      d[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < int(pr.size()) && pr[j] <= d[i] && i*pr[j] <= N; ++j) {
      d[i * pr[j]] = pr[j];
      if (i % pr[j] == 0) u[i * pr[j]] = 0;
      else u[i * pr[j]] = u[i] * u[pr[j]];
    }
  }
}

int main() {
  int n; cin >> n;
  vector<int> v;
  LL ones = 0;
  for (int i = 0, a; i < n; ++i) {
    cin >> a;
    if (a == 1) ++ones;
    else v.push_back(a);
  }
  n = v.size();
  for (int& i : v) cin >> i;
  sieve();

  vector<LL> cnt(N + 1);
  for (int i : v) {
    for (int j = 1; j*j <= i; ++j) {
      if (i % j) continue;
      ++cnt[j];
      if (j*j != i) ++cnt[i / j];
    }
  }
  LL ans = 0;
  for (int i = 1; i <= N; ++i) {
    ans += u[i] * cnt[i] * cnt[i];
  }
  ans /= 2; // unordered_pairs;
  ans += ones * n + ones*(ones-1)/2; // add ones
  cout << ans << "\n";
}

/*

*/
