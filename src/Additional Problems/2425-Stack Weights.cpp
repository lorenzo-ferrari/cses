#include "bits/stdc++.h"
using namespace std;
using LL = long long;

struct Segtree {
    struct nd {
        int mn;
        int mx;
        int lz;
        nd() : mn(0), mx(0), lz(0) {}
        nd(int _mn, int _mx)
            : mn(_mn), mx(_mx), lz(0) {}
    };
    nd join(nd a, nd b) {
        return nd(min(a.mn, b.mn), max(a.mx, b.mx));
    }

    int n;
    vector<nd> t;
    Segtree(int _n) {
        for (n = 1; n < _n; n <<= 1);
        t.resize(2 * n);
    }
    void apply(int i, int x) {
        t[i].mn += x;
        t[i].mx += x;
        t[i].lz += x;
    }
    void prop(int i) {
        if (i < n && t[i].lz) {
            apply(2*i  , t[i].lz);
            apply(2*i+1, t[i].lz);
        }
        t[i].lz = 0;
    }

    void add(int i, int a, int b, int l, int r, int x) {
        prop(i);
        if (r <= a || b <= l) return;
        if (l <= a && b <= r) apply(i, x);
        else {
            prop(i);
            add(2*i  , a, (a+b)/2, l, r, x);
            add(2*i+1, (a+b)/2, b, l, r, x);
            t[i] = join(t[2*i], t[2*i+1]);
        }
    }

    nd query(int i, int a, int b, int l, int r) {
        prop(i);
        if (r <= a || b <= l) return nd();
        if (l <= a && b <= r) return t[i];
        return join(
                query(2*i  , a, (a+b)/2, l, r),
                query(2*i+1, (a+b)/2, b, l, r)
                );
    }

    nd query(int l, int r) { return query(1, 0, n, l, r); }
    void add(int l, int r, int x) { add(1, 0, n, l, r, x); }
};

int main() {
    int n; cin >> n;
    Segtree st(n+5);
    for (int i = 0, a, w; i < n; ++i) {
        cin >> a >> w;
        if (w == 1) {
            st.add(0, a, +1);
        } else if (w == 2) {
            st.add(0, a, -1);
        }

        auto [mn, mx, _] = st.query(0, n+5);

        if (mx > 0 && mn == 0) {
            cout << ">\n";
        } else if (mx == 0 && mn < 0) {
            cout << "<\n";
        } else {
            cout << "?\n";
        }
    }
}
