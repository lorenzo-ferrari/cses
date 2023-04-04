/*
Task:              1077 Sliding Cost
Sender:            lorenzo_ferrari
Submission time:   2021-12-19 16:39:44
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifndef LORENZO
#define cerr if(0)cerr
#endif
#define watch(x) cerr << (#x) << " is " << x << "\n";

using namespace std;
using LL = long long;
using namespace __gnu_pbds;
using ordered_set = tree<
  pair<int,int>,
  null_type,
  less<pair<int,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update
>;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  LL n; cin >> n;
  LL k; cin >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ordered_set bst;
  for (int i = 0; i < k; ++i) bst.insert({a[i], i});
  int mid = bst.find_by_order((k-1)/2)->first;
  LL cl = 0, cg = 0;
  LL sl = 0, sg = 0;
  for (int i = 0; i < k; ++i) {
    if (a[i] <= mid) ++cl, sl += a[i];
    else ++cg, sg += a[i];
  }

  cout << sg - sl + (cl - cg) * mid << " ";

  bst.erase(bst.lower_bound({a[0], -1}));
  if (a[0] <= mid) --cl, sl -= a[0];
  else --cg, sg -= a[0];

  for (int i = k; i < n; ++i) {
    bst.insert({a[i], i});
    if (a[i] <= mid) ++cl, sl += a[i];
    else ++cg, sg += a[i];

    int nwmid = bst.find_by_order((k - 1) / 2)->first;

    auto it = bst.upper_bound({nwmid, 2*n});
    for (; it != bst.end() && it->first <= mid; ++it) {
      cerr << it->first << " cambia da <= a > \n";
      --cl, sl -= it->first;
      ++cg, sg += it->first;
    }
    it = bst.upper_bound({mid, 2*n});
    for (; it != bst.end() && it->first <= nwmid; ++it) {
      --cg, sg -= it->first;
      ++cl, sl += it->first;
    }

    mid = nwmid;
    cout << sg - sl + (cl - cg) * mid << " ";
    cerr << endl;

    bst.erase(bst.lower_bound({a[i-k+1], -1}));
    if (a[i-k+1] <= mid) --cl, sl -= a[i-k+1];
    else --cg, sg -= a[i-k+1];
  }
  cout << "\n";
}
