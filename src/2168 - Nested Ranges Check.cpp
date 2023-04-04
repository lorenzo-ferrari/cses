/*
Task:              2168 Nested Ranges Check
Sender:            lorenzo_ferrari
Submission time:   2021-12-13 23:16:01
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct fenwick {
  int n;
  vector<int> ft;
  fenwick(int _n) : n(_n) {
    ft.resize(n);
  }
  void upd(int i) { for (; i < n; i |= i+1) ++ft[i]; }
  int sum(int r) {
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ans += ft[r];
    return ans;
  }
  int sum(int l, int r) { return sum(r) - sum(l - 1); }
};

int n;
vector<int> x, y;

vector<int> solve() {
  vector<vector<array<int, 2>>> ep(2*n);
  for (int i = 0; i < n; ++i) {
    ep[x[i]].push_back({i, 0});
    ep[y[i]].push_back({i, 1});
  }
  fenwick ft(2 * n);
  vector<int> ans(n);
  for (int i = 0; i < 2*n; ++i) {
    for (auto [id, ty] : ep[i]) {
      if (ty == 1) {
        ft.upd(x[id]);
      }
    }
    for (auto [id, ty] : ep[i]) {
      if (ty == 1) {
        ans[id] = bool(ft.sum(x[id], y[id]) - 1);
      }
    }
  }
  return ans;
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cin >> n;
  x.resize(n);
  y.resize(n);
  vector<int> zip;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    zip.push_back(x[i]);
    zip.push_back(y[i]);
  }
  sort(zip.begin(), zip.end());
  zip.resize(unique(zip.begin(), zip.end()) - zip.begin());
  for (int& i : x) i = lower_bound(zip.begin(), zip.end(), i) - zip.begin();
  for (int& i : y) i = lower_bound(zip.begin(), zip.end(), i) - zip.begin();
  auto a = solve();
  zip.clear();
  for (int i = 0; i < n; ++i) {
    x[i] = 1e6 - x[i];
    y[i] = 2e6 - y[i];
    zip.push_back(x[i]);
    zip.push_back(y[i]);
  }
  sort(zip.begin(), zip.end());
  zip.resize(unique(zip.begin(), zip.end()) - zip.begin());
  for (int& i : x) i = lower_bound(zip.begin(), zip.end(), i) - zip.begin();
  for (int& i : y) i = lower_bound(zip.begin(), zip.end(), i) - zip.begin();
  auto b = solve();
  for (int i : a) cout << i << " ";
  cout << "\n";
  for (int i : b) cout << i << " ";
  cout << "\n";
}
