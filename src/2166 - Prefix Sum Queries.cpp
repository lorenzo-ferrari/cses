/*
Task:              2166 Prefix Sum Queries
Sender:            lorenzo_ferrari
Submission time:   2021-06-24 22:19:39
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

#ifdef SAS
const long long N = 1 << 10;
#else
const long long N = 1 << 20;
#endif

typedef long long ll;

struct nd {
    ll sum = 0;
    ll prf = 0;
    nd() {}
    nd(ll x) : sum(x), prf(x) {}
    nd(ll x, ll y) : sum(x), prf(y) {}
};

nd join(nd a, nd b) {
    return nd(a.sum + b.sum, std::max(a.prf, a.sum + b.prf));
}

nd t[2 * N];

nd query(int i, int a, int b, int l, int r) {
    if (r <= a || b <= l) return nd(0);
    if (l <= a && b <= r) return t[i];
    return join(query(i << 1    , a, (a + b) / 2, l, r),
                query(i << 1 | 1, (a + b) / 2, b, l, r));
}

void update(int p, int x) {
    for (t[p += N] = nd(x); p > 1; p>>= 1) {
        if (p & 1)
            t[p >> 1] = join(t[p ^ 1], t[p]);
        else
            t[p >> 1] = join(t[p], t[p ^ 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        t[i + N] = nd(x);
    }
    for (int i = N - 1; i > 0; --i)
        t[i] = join(t[i << 1], t[i << 1 | 1]);

    for (int i = 0, a, b, c; i < q; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b - 1, c);
        } else {
            cout << std::max(query(1, 0, N, b - 1, c).prf, 0LL) << "\n";
        }
    }
}
