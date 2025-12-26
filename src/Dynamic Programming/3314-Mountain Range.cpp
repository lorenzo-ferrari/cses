#include "bits/stdc++.h"
using namespace std;
using LL = long long;

struct Segtree {
	int n;
	vector<int> t;
	Segtree() {}
	Segtree(int n) : n(n), t(2 * n) {}
	void upd(int p, int v) {
		for (t[p += n] = v; p > 1; p >>= 1)
			t[p >> 1] = max(t[p], t[p ^ 1]);
	}
	int query(int l, int r) {
		int ans = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ans = max(ans, t[l++]);
			if (r & 1) ans = max(ans, t[--r]);
		}
		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	auto z = h;
	sort(begin(z), end(z));
	z.erase(unique(begin(z), end(z)), end(z));
	for (int& x : h) {
		x = lower_bound(begin(z), end(z), x) - begin(z);
	}
	vector<vector<int>> htoi(n);
	for (int i = 0; i < n; ++i) {
		htoi[h[i]].push_back(i);
	}

	Segtree st(n);
	set<int> higher;
	for (int i = 0; i < n; ++i)
		higher.insert(i);
	vector<int> dp(n);
	for (int ht = 0; ht < n; ++ht) {
		for (int i : htoi[ht]) {
			auto it = higher.find(i);
			int l = (it == begin(higher) ? 0 : *prev(it) + 1);
			int r = (next(it) == end(higher) ? n : *next(it));
			dp[i] = 1 + max(st.query(l, i), st.query(i + 1, r));
		}
		for (int i : htoi[ht]) {
			higher.erase(i);
			st.upd(i, dp[i]);
		}
	}

	cout << st.query(0, n) << "\n";
}
