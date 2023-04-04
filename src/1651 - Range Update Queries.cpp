/*
Task:              1651 Range Update Queries
Sender:            lorenzo_ferrari
Submission time:   2023-02-22 17:19:41
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct Segment {
  int n;
  vector<LL> t;
  Segment(int _n, vector<int> a) {
    for (n = 1; n < _n; n <<= 1)
      ;
    t.resize(2 * n);
    for (int i = 0; i < _n; ++i) {
      t[i + n] = a[i];
    }
  }
  void update(int i, int tl, int tr, int l, int r, LL x) {
    if (tr < l || r < tl)
      return;
    if (l <= tl && tr <= r)
      t[i] += x;
    else {
      int tm = (tl + tr) / 2;
      update(2 * i, tl, tm, l, r, x);
      update(2 * i + 1, tm + 1, tr, l, r, x);
    }
  }
  LL query(int p) {
    LL ans = 0;
    for (p += n; p > 0; p >>= 1) {
      ans += t[p];
    }
    return ans;
  }

  void update(int l, int r, LL x) { update(1, 0, n - 1, l, r, x); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  Segment st(n, a);
  for (int t, a, b, c; q--;) {
    cin >> t;
    if (t == 1) {
      cin >> a >> b >> c;
      st.update(a - 1, b - 1, c);
    } else {
      cin >> a;
      cout << st.query(a - 1) << "\n";
    }
  }
}
