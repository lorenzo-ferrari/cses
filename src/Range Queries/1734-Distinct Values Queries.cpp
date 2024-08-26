#include <bits/stdc++.h>
using namespace std;

static constexpr int BS = 512;

struct S {
	int n, cnt;
	vector<int> frq;
	S(int _n) : n(_n), cnt(0), frq(n, 0) {}

	void insert(int x) {
		cnt += (frq[x] == 0);
		++frq[x];
	}

	void erase(int x) {
		cnt -= (frq[x] == 1);
		--frq[x];
	}

	int get() {
		return cnt;
	}
};
 
int main() {
	int n; cin >> n;
	int q; cin >> q;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	{	// compressione di a
		// [100, 6, 2, 999, 100] -> [2, 1, 0, 3, 2]
		auto zip = a;
		sort(begin(zip), end(zip));
		zip.erase(unique(begin(zip), end(zip)), end(zip));
		for (int& i : a) {
			i = lower_bound(begin(zip), end(zip), i) - begin(zip);
		}
	}
	vector<array<int, 3>> qs(q);
	for (int i = 0, a, b; i < q; ++i) {
		cin >> a >> b;
		--a, --b;
		qs[i] = {a, b, i};
	}
	sort(begin(qs), end(qs), [&](array<int, 3> x, array<int, 3> y){
		if (x[0] / BS == y[0] / BS) {
			return x[1] < y[1];
		} else {
			return x[0] < y[0];
		}
	});

	S s(n);

	int cl = 0, cr = -1;
	vector<int> ans(q);
	for (auto [l, r, i] : qs) {
		while (cr < r) { ++cr; s.insert(a[cr]); }
		while (cr > r) { s.erase(a[cr]); --cr; }
		while (cl < l) { s.erase(a[cl]); ++cl; }
		while (cl > l) { --cl; s.insert(a[cl]); }
		ans[i] = s.get();
	}

	for (int i = 0; i < q; ++i) {
		cout << ans[i] << "\n";
	}
}
