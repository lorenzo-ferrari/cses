#include <iostream>
#include <vector>
using namespace std;

#define int long long

const int N = 1 << 18;
const int INF = 1e9;

struct nd {
	int sum = 0;
	int arr = -INF;
	int pref = -INF;
	int suff = -INF;

	nd() {}
	nd(int x) : sum(x), arr(x), pref(x), suff(x) {}
};

nd join(nd a, nd b) {
	nd ans;
	ans.sum = a.sum + b.sum;
	ans.arr = max(max(a.arr, b.arr), a.suff + b.pref);
	ans.pref = max(a.pref, a.sum + b.pref);
	ans.suff = max(b.suff, a.suff + b.sum);
	return ans;
}

struct st {
	nd t[2 * N];

	st(vector<int> a) {
		for (int i = 0; i < a.size(); i++)
			t[i + N] = nd(a[i]);
		for (int i = N - 1; i > 0; i--)
			t[i] = join(t[i << 1], t[i << 1 | 1]);
	}

	void update(int p, int val) {
		t[p += N] = nd(val);
		for (; p > 1; p >>= 1)
			t[p >> 1] = (p & 1) ? join(t[p ^ 1], t[p]) : join(t[p], t[p ^ 1]);
	}
};

int32_t main() {
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int &i : a)
		cin >> i;

	st t(a);

	for (int k, x; q--;) {
		cin >> k >> x;
		t.update(k-1, x);
	    cout << std::max(0LL, t.t[1].arr) << "\n";
	}
}
