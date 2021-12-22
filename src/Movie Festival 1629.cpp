#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

struct t {
    int a, b;
    t(int A = 0, int B = 0) :
        a(A), b(B) {}
};

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin >> n;

    vector<t> v(n);
    vector<int> c(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].a >> v[i].b;
        c[i << 1    ] = v[i].a;
        c[i << 1 | 1] = v[i].b;
    }

    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());

    for (int i = 0; i < n; ++i) {
        v[i].a = lower_bound(c.begin(), c.end(), v[i].a) - c.begin();
        v[i].b = lower_bound(c.begin(), c.end(), v[i].b) - c.begin();
    }

    sort(v.begin(), v.end(), [&](t i, t j) { return i.a < j.a; });

    vector<int> dp(2 * n);
    for (int i = 0, j = 0; i < 2 * n; ++i) {
        if (i) dp[i] = max(dp[i], dp[i - 1]);
        while (j < n && v[j].a == i) {
            dp[v[j].b] = max(dp[v[j].b], dp[i] + 1);
            ++j;
        }
    }

    cout << dp.back() << "\n";
}

