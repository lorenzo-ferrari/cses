#pragma GCC optimize("O3")
#include "bits/stdc++.h"
using namespace std;
using LL = long long;

class Hash {
    static constexpr int SZ = 1;
    static constexpr long long mod = 2e9 + 11;
    static constexpr array<LL, SZ> pr{29};
    
    long long n;
    string s;
    vector<array<LL, SZ>> hsh;
    vector<array<LL, SZ>> pws;

public:
    Hash(int _n, string _s) : n(_n), s(_s) {
        hsh.resize(n + 1);
        pws.resize(n + 1);
        for (int j = 0; j < SZ; ++j) {
            hsh[0][j] = 0;
            pws[0][j] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < SZ; ++j) {
                pws[i][j] = pws[i - 1][j] * pr[j] % mod;
                hsh[i][j] = pr[j] * hsh[i - 1][j] + (s[i - 1] - '`');
                hsh[i][j] %= mod;
            }
        }
    }

    array<LL, SZ> get_hash(int l, int len) {
        array<LL, SZ> ans;
        for (int j = 0; j < SZ; ++j) {
            ans[j] = (hsh[l + len][j] - hsh[l][j] * pws[len][j] % mod + mod) % mod;
        }
        return ans;
    }

    bool same(int l, int r, int len) {
        return get_hash(l, len) == get_hash(r, len);
    }
};

int odd_pal(int n, string s) {
    Hash hs(n, s);
    reverse(begin(s), end(s));
    Hash hr(n, s);

    int idx = -1, len = 0;
    for (int i = 0; i < n; ++i) {
        int l = len, r = min(i+1, n-i)+1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            auto h1 = hs.get_hash(i, m);
            auto h2 = hr.get_hash(n - 1 - i, m);
            if (h1 == h2) {
                l = m;
            } else {
                r = m;
            }
        }
        if (l > len) {
            idx = i;
            len = l;
        }
    }

    return idx;
}

int main() {
    string s; cin >> s;
    int n = s.size();

    string ss = "#";
    for (int i = 0; i < n; ++i) {
        ss.push_back(s[i]);
        ss.push_back('#');
    }
    int nn = ss.size();

    int c = odd_pal(nn, ss);

    int len = 1;
    while (c >= len && c + len < nn) {
        if (ss[c - len] == ss[c + len]) {
            ++len;
        } else {
            break;
        }
    }
    --len;
    for (int i = c - len + 1; i < c + len; i += 2) {
        cout << ss[i];
    }
    cout << "\n";
}
