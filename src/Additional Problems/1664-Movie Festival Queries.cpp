#include "bits/stdc++.h"
using namespace std;
using LL = long long;

struct Segment {
    int n;
    vector<int> t;
    Segment(int n) : n(n), t(2*n, 1e9) {}
    int query(int p) {
        int ans = 1e9;
        for (p += n; p > 0; p >>= 1) {
            ans = min(ans, t[p]);
        }
        return ans;
    }
    void upd(int a, int b, int mn) {
        for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
            if (a & 1) { t[a] = min(t[a], mn); a++; }
            if (b & 1) { --b; t[b] = min(t[b], mn); }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int q; cin >> q;

    vector<array<int, 2>> v(n);
    for (auto& [a, b] : v) {
        cin >> a >> b;
    }

    static constexpr int M = 1e6 + 5;
    static constexpr int LG= 20;
    Segment st(M);
    for (auto [a, b] : v) {
        st.upd(0, a+1, b);
    }

    vector<array<int, LG>> up(M);
    for (int i = 0; i < M; ++i) {
        up[i][0] = st.query(i);
    }
    for (int i = 1; i < LG; ++i) {
        for (int j = 0; j < M; ++j) {
            if (up[j][i-1] < M) {
                up[j][i] = up[up[j][i-1]][i-1];
            } else {
                up[j][i] = 1e9;
            }
        }
    }

    for (int a, b; q--;) {
        cin >> a >> b;
        int ans = 0;
        for (int i = LG-1; i >= 0; --i) {
            if (up[a][i] <= b) {
                ans += (1 << i);
                a = up[a][i];
            }
        }
        cout << ans << "\n";
    }
}
