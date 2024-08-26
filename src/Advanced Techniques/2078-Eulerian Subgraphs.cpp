#include "bits/stdc++.h"
using namespace std;
using LL = long long;

static constexpr int mod = 1e9 + 7;

struct Dsu {
    vector<int> p;
    Dsu(int n) : p(n) {
        iota(begin(p), end(p), 0);
    }
    int find(int v) {
        return p[v] == v ? v : p[v] = find(p[v]);
    }
    void onion(int a, int b) {
        a = find(a);
        b = find(b);
        p[b] = a;
    }
};

int main() {
    int n; cin >> n;
    int m; cin >> m;
    Dsu dsu(n);
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b; --a, --b;
        dsu.onion(a, b);
    }

    int cc = 0;
    for (int i = 0; i < n; ++i) {
        cc += (dsu.p[i] == i);
    }

    int ans = 1;
    for (int i = 0; i < m-n+cc; ++i) {
        ans = 2 * ans % mod;
    }

    cout << ans << "\n";
}
