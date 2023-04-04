/*
Task:              1735 Range Updates and Sums
Sender:            lorenzo_ferrari
Submission time:   2023-02-22 18:25:37
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

const long long N = (1LL << 20);
const long long INF = (1LL << 60);

class lazySegment {
	struct node {
		long long sum = 0;
		long long lazy = 0;
        long long sett = INF;
		node (long long _sum = 0) : sum(_sum) {}
	};

	node join(node &a, node &b) { return node(a.sum + b.sum); }

	node st[2 * N];

public:
	lazySegment () {}
	lazySegment (std::vector<long long> a) {
		for (int i = 0; i < (int)a.size(); ++i)
			st[i + N] = node(a[i]);
		for (int i = N - 1; i > 0; --i)
			st[i] = join(st[i << 1], st[i << 1 | 1]);
	}

    void apply_sett(long long i, long long x) {
        st[i].lazy = 0;
        st[i].sett = x;
    }

    void apply_lazy(long long i, long long x) {
        if (st[i].sett != INF)
            st[i].sett += x;
        else
            st[i].lazy += x;
    }

	void prop(long long i, long long a, long long b) {
		if (st[i].lazy) {
            assert(st[i].sett == INF);
			st[i].sum += (b - a) * st[i].lazy;
			if (i < N) {
				apply_lazy(i << 1    , st[i].lazy);
				apply_lazy(i << 1 | 1, st[i].lazy);
			}
			st[i].lazy = 0;
		}
        if (st[i].sett != INF) {
            st[i].sum = (b - a) * st[i].sett;
			if (i < N) {
				apply_sett(i << 1    , st[i].sett);
				apply_sett(i << 1 | 1, st[i].sett);
			}
			st[i].sett = INF;
        }
	}

	void _add(int i, int l, int r, int a, int b, long long val) {
		prop(i, a, b);
		if (r <= a || b <= l) return;
		if (l <= a && b <= r) {
            apply_lazy(i, val);
			prop(i, a, b);
		}
		else {
			_add(i << 1    , l, r, a, (a + b) >> 1, val);
			_add(i << 1 | 1, l, r, (a + b) >> 1, b, val);
			st[i] = join(st[i << 1], st[i << 1 | 1]);
		}
	}

    void _set(int i, int l, int r, int a, int b, int x) {
		prop(i, a, b);
		if (r <= a || b <= l) return;
		if (l <= a && b <= r) {
			apply_sett(i, x);
			prop(i, a, b);
		}
		else {
			_set(i << 1    , l, r, a, (a + b) >> 1, x);
			_set(i << 1 | 1, l, r, (a + b) >> 1, b, x);
			st[i] = join(st[i << 1], st[i << 1 | 1]);
		}
    }

	long long _sum(int i, int l, int r, int a, int b) {
		prop(i, a, b);
		if (r <= a || b <= l) return 0;
		if (l <= a && b <= r) return st[i].sum;
		return _sum(i << 1    , l, r, a, (a + b) >> 1) +
					 _sum(i << 1 | 1, l, r, (a + b) >> 1, b);
	}

	long long sum(int l, int r) { return _sum(1, l, r, 0, N); }
	void add(int l, int r, long long x) { _add(1, l, r, 0, N, x); }
	void set(int l, int r, long long x) { _set(1, l, r, 0, N, x); }
};

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (long long& i : a)
        cin >> i;

    lazySegment t(a);
    for (int x, a, b, c; q--;) {
        cin >> x >> a >> b;
        if (x == 1) {
            cin >> c;
            t.add(a-1, b, c);
        } else if (x == 2) {
            cin >> c;
            t.set(a-1, b, c);
        } else {
            cout << t.sum(a-1, b) << "\n";
        }
    }
}

