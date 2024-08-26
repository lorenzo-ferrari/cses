#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
  pair<int,int>,
  null_type,
  less<pair<int,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int k; cin >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ordered_set bst;
  for (int i = 0; i < k - 1; ++i) bst.insert({a[i], i});
  for (int i = k - 1; i < n; ++i) {
    bst.insert({a[i], i});
    cout << (bst.find_by_order((k - 1) / 2)->first) << " ";
    bst.erase(bst.lower_bound({a[i-k+1], -1}));
  }
  cout << "\n";
}
