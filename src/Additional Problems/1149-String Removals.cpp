#include "bits/stdc++.h"
using namespace std;
using LL = long long;

static constexpr LL mod = 1e9 + 7;

int main() {
    string s; cin >> s;
    
    LL sum = 0;
    array<LL, 128> dp{};
    for (char c : s) {
        int dpc = (sum + 1) % mod;
        sum = (sum + dpc - dp[c] + mod) % mod;
        dp[c] = dpc;
    }

    cout << sum << "\n";
}
