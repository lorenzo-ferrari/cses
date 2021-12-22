#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n), b(n), c(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        c[i << 1    ] = a[i];
        c[i << 1 | 1] = b[i];
    }

    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());

    vector<int> prf(2 * n);
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
        b[i] = lower_bound(c.begin(), c.end(), b[i]) - c.begin();
        ++prf[a[i]];
        --prf[b[i]];
    }

    int ans = prf[0];
    for (int i = 1; i < 2 * n; i++) {
        prf[i] += prf[i - 1];
        ans = max(ans, prf[i]);
    }

    cout << ans << "\n";
}

