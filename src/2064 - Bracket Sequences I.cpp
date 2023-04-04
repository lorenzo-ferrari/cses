/*
Task:              2064 Bracket Sequences I
Sender:            lorenzo_ferrari
Submission time:   2022-11-29 20:52:17
Language:          C++17
Result:            ACCEPTED
*/
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
    int n; cin >> n;
    if (n & 1) {
        cout << "0\n";
        return 0;
    }
    n >>= 1;
    
    vector<LL> f(2*n+1); f[0] = 1;
    for (int i = 1; i <= 2*n; ++i) {
        f[i] = f[i - 1] * i % mod;
    }

    LL ans = f[2*n];
    ans = ans * inv(f[n]) % mod;
    ans = ans * inv(f[n]) % mod;
    ans = ans * inv(n+1) % mod;

    cout << ans << "\n";
}
