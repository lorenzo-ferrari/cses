#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

static constexpr int SZ = 3;
static constexpr LL mod = 2e9 + 11;
static constexpr array<LL, SZ> pr{29, 31, 37};

struct Hash {
    int n;
    string s;
    vector<array<LL, SZ>> hsh;
    vector<array<LL, SZ>> pws;

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

template<typename T, size_t N>
struct std::hash<std::array<T, N>> {
    size_t operator()(const std::array<T, N>& key) const {
        std::hash<T> hasher;
        size_t res = 0;
        for (size_t i = 0; i < N; ++i) {
            res = (res << 1) ^ hasher(key[i]);
        }
        return res;
    }
};

int main() {
    string s; cin >> s;
    int n = s.size();

    Hash hash(n, s);

    int l = 0, r = n;
    unordered_set<array<LL, SZ>> seen;
    int idx = -1;
    while (r - l > 1) {
        int m = (l + r) / 2;

        bool works = false;
        seen.clear();
        for (int i = 0; i <= n - m; ++i) {
            auto h = hash.get_hash(i, m);
            if (seen.count(h)) {
                works = true;
                idx = i;
                break;
            } else {
                seen.insert(h);
            }
        }

        if (works) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << (l == 0 ? "-1" : s.substr(idx, l)) << "\n";
}
