#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    int n; cin >> n;
    vector<LL> a(n), prf(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prf[i + 1] = prf[i] + a[i];
    }
    auto sum = [&](int l, int r) -> LL {
        return prf[r+1] - prf[l];
    };
    static constexpr LL INF = 1e15;
    vector<vector<LL>> dp(n, vector<LL>(n, INF));
    vector<vector<LL>> jj(n, vector<LL>(n, INF));
    for (int i = 0; i < n; ++i) { dp[i][i] = 0, jj[i][i] = i; }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len - 1;
            LL s = sum(i, j);
            for (int k = jj[i][j-1]; k <= jj[i+1][j] && k+1 < n; ++k) {
                if (dp[i][j] > s + dp[i][k] + dp[k+1][j]) {
                    dp[i][j] = s + dp[i][k] + dp[k+1][j];
                    jj[i][j] = k;
                }
            }
        }
    }
    cout << dp[0][n-1] << "\n";
}

