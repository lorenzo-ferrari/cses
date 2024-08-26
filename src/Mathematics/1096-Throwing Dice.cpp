#include <bits/stdc++.h>
using namespace std;
using LL = long long;

static constexpr LL mod = 1e9 + 7;

unordered_map<LL, LL> dp;

LL solve(LL n) {
    if (dp.count(n)) return dp[n];

    LL nn = n/2;
    LL ans = solve(nn) * solve(n - nn) % mod;
    
    for (int i = 2; i <= 6; ++i) {
        for (int j = 1; j < i; ++j) {
            ans += solve(nn - j) * solve(n - nn - i + j);
            ans %= mod;
        }
    }
    
    return dp[n] = ans;
}

int main() {
    dp[0] = 1;
    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j <= i && j <= 6; ++j) {
            dp[i] += dp[i - j];
        }
        dp[i] %= mod;
    }
    LL n; cin >> n;
    cout << solve(n) << "\n";
}
