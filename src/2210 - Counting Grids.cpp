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
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
LL inv(LL x) { return fxp(x, mod - 2); }

int main() {
    LL n; cin >> n;
    LL ans = 0;
    if (n & 1) {
        ans += fxp(2, n*n);
        ans += fxp(2, n*n/4 + 1);
        ans += fxp(2, n*n/2 + 1);
        ans += fxp(2, n*n/4 + 1);
        ans %= mod;
        ans = ans * inv(4) % mod;
    } else {
        ans += fxp(2, n*n);
        ans += fxp(2, n*n/4);
        ans += fxp(2, n*n/2);
        ans += fxp(2, n*n/4);
        ans %= mod;
        ans = ans * inv(4) % mod;
    }
    cout << ans << "\n";
}

