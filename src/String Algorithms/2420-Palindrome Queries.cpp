#include "bits/stdc++.h"
using namespace std;
using LL = long long;

static constexpr int SZ = 3;
static constexpr LL mod = 2e9 + 11;
static constexpr array<LL, SZ> pr{29, 31, 37};

static constexpr int N = 2e5 + 42;

array<LL, SZ> pws[N];

void init() {
    for (int j = 0; j < SZ; ++j) pws[0][j] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < SZ; ++j) {
            pws[i][j] = pws[i - 1][j] * pr[j] % mod;
        }
    }
}

struct Segtree {
    struct nd {
        array<LL, SZ> hsh{};
        array<LL, SZ> rev{};
        int cnt{};

        nd() {}
        nd(char c) : cnt(1) {
            for (int j = 0; j < SZ; ++j) {
                hsh[j] = rev[j] = (c - '`') % mod;
            }
        }

        bool pal() const {
            return hsh == rev;
        }
    };
    nd join(const nd& a, const nd& b) {
        nd ans;
        for (int j = 0; j < SZ; ++j) {
            ans.hsh[j] = (a.hsh[j] * pws[b.cnt][j] + b.hsh[j]) % mod;
            ans.rev[j] = (a.rev[j] + b.rev[j] * pws[a.cnt][j]) % mod;
        }
        ans.cnt = a.cnt + b.cnt;
        return ans;
    }

    int n;
    vector<nd> t;

    Segtree(int _n, string s) {
        for (n = 1; n < _n; n <<= 1);
        t.resize(2 * n);
        s.resize(n, '#');
        for (int i = 0; i < n; ++i) {
            t[i + n] = nd(s[i]);
        }
        for (int i = n - 1; i > 0; --i) {
            t[i] = join(t[2 * i], t[2 * i + 1]);
        }
    }

    void update(int p, char c) {
        for (t[p += n] = nd(c); p > 1; p >>= 1) {
            t[p >> 1] = join(t[p & ~1], t[p | 1]);
        }
    }

    bool query(int l, int r) {
        nd ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ansl = join(ansl, t[l++]);
            if (r & 1) ansr = join(t[--r], ansr);
        }
        return join(ansl, ansr).pal();
    }
};

int main() {
    init();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int m; cin >> m;
    string s; cin >> s;
    Segtree st(n, s);

    for (int i = 0, t; i < m; ++i) {
        cin >> t;
        if (t == 1) {
            int k; cin >> k; --k;
            char x; cin >> x;
            st.update(k, x);
        } else {
            int a; cin >> a; --a;
            int b; cin >> b;
            if (st.query(a, b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    } 
}
