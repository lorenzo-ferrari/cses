#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    int n; cin >> n;
    int a; cin >> a;
    int b; cin >> b;

    int nn = 6*n;
    vector<double> dp(nn+10); dp[0] = 1.0;
    while (n--) {
        auto prv = dp;
        fill(begin(dp), end(dp), 0);
        for (int i = 0; i <= nn; ++i) {
            for (int j = 1; j <= 6; ++j) {
                dp[i + j] += prv[i] / 6;
            }
        }
    }
    double ans = 0;
    for (int i = a; i <= b; ++i) {
        ans += dp[i];
    }
    cout << fixed << setprecision(6) << ans << "\n";
}

