#include "bits/stdc++.h"
using namespace std;
using LL = long long;

static constexpr LL mod = 1e9 + 7;
static constexpr int N = 101;
static constexpr int X = 10001;

int main() {
    int n; cin >> n;
    int x; cin >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(begin(a), end(a), greater<int>());

    // dp[i][#open teams][penalty]
    // open a team: increase penalty by a[i]
    // close a team: decrease penalty by a[i]
    static LL dp[N][N][X]{};
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int o = 0; o <= i; ++o) {
            for (int p = 0; p < X; ++p) {
                if (!dp[i][o][p]) continue;
                dp[i+1][o][p] += dp[i][o][p] * (o + 1);
                dp[i+1][o][p] %= mod;
                if (o && p >= a[i]) {
                    dp[i+1][o-1][p-a[i]] += dp[i][o][p] * o;
                    dp[i+1][o-1][p-a[i]] %= mod;
                }
                if (p + a[i] < X) {
                    dp[i+1][o+1][p+a[i]] += dp[i][o][p];
                    dp[i+1][o+1][p+a[i]] %= mod;
                }
            }
        }
    }
    LL ans = 0;
    for (int p = 0; p <= x; ++p) {
        ans += dp[n][0][p];
    }
    ans %= mod;

    cout << ans << "\n";
}
