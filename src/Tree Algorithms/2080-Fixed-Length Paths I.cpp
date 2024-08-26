#include <bits/stdc++.h>
using namespace std;

struct EnrichedMap {
  int inc = 0;
  unordered_map<int, int> mp;
  EnrichedMap(){}
  void insert(int a, int b = 1) {
    mp[a - inc] += b;
  }
  void increase(int x) {
    inc += x;
  }
  vector<pair<int, int>> get_elements() {
    vector<pair<int, int>> ans;
    ans.reserve(mp.size());
    for (auto [a, b] : mp) {
      ans.push_back({a+inc, b});
    }
    return ans;
  }
  int size() { return mp.size(); }
  int& operator [](int i){ return mp[i - inc]; }
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
  int k; cin >> k;
  vector<vector<int>> adj(n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    cin >> a >> b; --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  long long ans = 0;
  auto paths = [&](auto&& self, int v, int p) -> EnrichedMap {
    EnrichedMap tot; tot[0] = 1;
    for (int u : adj[v]) {
      if (u == p) continue;
      auto mc = self(self, u, v);
      mc.increase(1);
      if (mc.size() > tot.size()) swap(mc, tot);
      for (auto [a, b] : mc.get_elements()) {
        int target = k - a;
        ans += (long long) tot[target] * b;
      }
      for (auto [a, b] : mc.get_elements()) {
        tot.insert(a, b);
      }
    }
    return tot;
  };
  auto m = paths(paths, 0, -1);
  cout << ans << "\n";
}
