/*
Task:              2187 Bracket Sequences II
Sender:            lorenzo_ferrari
Submission time:   2022-12-19 23:31:21
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

LL solve(int n, int k) {
    if (k == n) return 1LL;
    vector<LL> f(2*n + 1); f[0] = 1;
    for (int i = 1; i <= 2*n; ++i) {
        f[i] = f[i-1]*i % mod;
    }
    auto choose = [&](LL a, LL b) -> LL {
        LL ans = f[a];
        ans = ans * inv(f[b]) % mod;
        ans = ans * inv(f[a - b]) % mod;
        return ans;
    };
    LL ans = choose(2*n - k, n);
    ans = (ans - choose(2*n - k, n+1) + mod) % mod;
    return ans;
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int op = 0;
    for (char c : s) {
        op += (c == '(');
        op -= (c == ')');
        if (op < 0) {
            cout << "0\n";
            return 0;
        }
    }
    if ((n & 1) || ((int)s.size() + op > n)) {
        cout << "0\n";
        return 0;
    }
    cout << solve((n - s.size() + op) / 2, op) << "\n";
}
