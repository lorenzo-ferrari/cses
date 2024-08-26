#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct Segment {
    int n;
    vector<LL> t;
    Segment(int n) : n(n), t(2 * n) {}
    void update(int l, int r, LL x) {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) t[l++] += x;
            if (r & 1) t[--r] += x;
        }
    }
    LL query(int p) {
        LL ans = 0;
        for (p += n; p > 0; p >>= 1) {
            ans += t[p];
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int q; cin >> q;
    Segment st(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        st.update(i, i+1, x);
    }
    for (int i = 0, t, a, b, u, k; i < q; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b >> u;
            --a, --b;
            st.update(a, b+1, u);
        } else {
            cin >> k;
            cout << st.query(k - 1) << "\n";
        }
    }
}
