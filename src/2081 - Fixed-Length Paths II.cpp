#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct StaticToDynamic {
  // v can be divided in O(log n) ordered subarrays
  // the length of the subarrays are the 1s in the binary representation of n
  vector<int> v;

  void insert(int x) {
    // O(log n) amortized

    v.push_back(x);

    for (size_t i = 1; !(i & v.size()); i *= 2) {
      inplace_merge(v.end() - 2 * i, v.end() - i, v.end());
    }
  }

  int count(int a, int b) {
    // count the elements in [a, b], O(log^2 n)

    int ans = 0;
    for (size_t n = v.size(); n; n &= n - 1) {
      size_t lsb = n & -n;
      auto l = lower_bound(v.begin() + n - lsb, v.begin() + n, a);
      auto u = upper_bound(v.begin() + n - lsb, v.begin() + n, b);
      ans += u - l;
    }
    return ans;
  }
};

struct ImprovedSet {
  int inc = 0;
  StaticToDynamic s;
  void insert(int x) { s.insert(x - inc); }
  void increase(int x) { inc += x; }
  size_t size() { return s.v.size(); }
  int count(int a, int b) { b = max(b, a-1); return s.count(a - inc, b - inc); }
  vector<int> get() {
    auto v = s.v;
    for (int& i : v) i += inc;
    return v;
  }
};

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#endif
  int n; cin >> n;
  int k1; cin >> k1;
  int k2; cin >> k2;
  vector<vector<int>> adj(n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    cin >> a >> b; --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  auto count = [&](int k) -> LL {
    LL ans = 0;
    auto paths = [&](auto&& self, int v, int p) -> ImprovedSet {
      ImprovedSet tot; tot.insert(0);
      for (int u : adj[v]) {
        if (u == p) continue;
        auto mc = self(self, u, v); mc.increase(1);
        if (mc.size() > tot.size()) swap(mc, tot);
        for (int x : mc.get()) {
          int m = k - x;
          ans += tot.count(0, m);
        }
        for (int a : mc.get()) {
          tot.insert(a);
        }
      }
      return tot;
    };
    paths(paths, 0, -1);
    return ans;
  };

  LL ans = count(k2) - count(k1 - 1);
  cout << ans << "\n";
}

