#include <bits/stdc++.h>
using namespace std;

constexpr int LOG = 18;
constexpr int N = 2e5 + 5;

int up[N][LOG];
// up[i][j] = "dove finisco dopo 2^j salti?"
// up[i][0] = par[i]
// up[i][j] = up[ up[i][j-1] ][j-1], 2^j = 2^{j-1} + 2^{j-1}

int lift(int v, int k) {
    for (int i = 0; i < LOG; ++i) {
        if (v == -1) {
            break;
        }
        if (k & (1 << i)) { // 2^i sta nella rappr. binaria di k
            v = up[v][i];
        }
    }
    return v;
}

int main() {
    int n; cin >> n;
    int q; cin >> q;
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i]; --p[i];
    }
    p[0] = -1;

    for (int i = 0; i < n; ++i) {
        up[i][0] = p[i];
    }
    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            if (up[i][j-1] == -1) {
                up[i][j] = -1;
            } else {
                up[i][j] = up[ up[i][j-1] ][j-1];
            }
        }
    }

    for (int i = 0, a, k; i < q; ++i) {
        cin >> a >> k; --a;
        int ans = lift(a, k);
        if (ans == -1) {
            cout << -1 << "\n";
        } else {
            cout << ans+1 << "\n";
        }
    }
}
