#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

struct segment {
	int n;
	vector<int> st;

	segment(vector<int> a) {
		n = a.size();
        st.resize(2 * n);
		for (int i = 0; i < n; i++)
            st[i + n] = a[i];
		for (int i = n - 1; i > 0; i--)
            st[i] = std::min(st[i << 1], st[i << 1 | 1]);
    }

	void update(int p, int val) {
		for (st[p += n] = val; p > 1; p >>= 1)
            st[p >> 1] = std::min(st[p], st[p ^ 1]);
	}

	int query(int l, int r) {
    int ans = 2e9;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ans = std::min(ans, st[l++]);
			if (r & 1) ans = std::min(ans, st[--r]);
		}
		return ans;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    vector<int> s1(n);
    vector<int> s2(n);
    iota(s1.begin(), s1.end(), 0);
    for (int i = 0; i < n; ++i) s2[i] = n - 1 - s1[i];

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        s1[i] += p[i];
        s2[i] += p[i];
    }

    segment lr(s1);
    segment rl(s2);
    for (int i = 0, a, k, x; i < q; ++i) {
        cin >> a >> k; --k;
        if (a == 1) {
            cin >> x;
            s1[k] -= p[k]; s2[k] -= p[k];
            p[k] = x;
            s1[k] += p[k]; s2[k] += p[k];
            lr.update(k, s1[k]);
            rl.update(k, s2[k]);
        } else {
            cout << std::min(lr.query(k, n) - k, rl.query(0, k + 1) - n + 1 + k) << "\n";
        }
    }
}
