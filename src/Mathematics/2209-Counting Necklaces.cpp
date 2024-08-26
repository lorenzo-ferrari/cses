#include <bits/stdc++.h>
using namespace std;
using LL = long long;

static constexpr LL mod = 1e9 + 7;

LL fxp(LL x, LL y) {
    LL ans = 1;
    while (y) {
        if (y & 1) {
            ans = ans * x % mod;
        }
        x = x *x % mod;
        y >>= 1;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<LL> pw(n+1); pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * m % mod;
    }
    LL ans = 0;
    for (int k = 0; k < n; ++k) {
        ans += pw[__gcd(k, n)];
        ans %= mod;
    }
    ans = ans * fxp(n, mod - 2) % mod;
    cout << ans << "\n";
}
