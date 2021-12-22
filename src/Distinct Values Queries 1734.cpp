#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> t(2 * n);
    vector<int> x(n);
    vector<int> v(n);
    map<int, int> p;
    for (int& i : x) cin >> i;
    for (int i = n - 1; i >= 0; --i) {
        v[i] = p[x[i]]; if (!v[i]) v[i] = 1e9;
        p[x[i]] = i;
        t[i + n].push_back(v[i]);
    }
    for (int i = n - 1; i > 0; --i) {
        t[i].resize(t[i << 1].size() + t[i << 1 | 1].size());
        merge(t[i<<1].begin(), t[i<<1].end(), t[i<<1|1].begin(), t[i<<1|1].end(), t[i].begin());
    }

    for (int i = 0, a, b, B; i < q; ++i) {
        cin >> a >> b; --a; B = b;
        int ans = b - a;
        for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
            if (a & 1) {
                ans -= lower_bound(t[a].begin(), t[a].end(), B) - t[a].begin();
                a++;
            }
            if (b & 1) {
                --b;
                ans -= lower_bound(t[b].begin(), t[b].end(), B) - t[b].begin();

            }
        }
        cout << ans << "\n";
    }
}

