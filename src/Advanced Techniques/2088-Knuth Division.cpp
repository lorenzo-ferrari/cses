#include <bits/stdc++.h>
using namespace std;
using LL = long long;

static constexpr LL INF = 1e15;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<LL> prf(n + 1);
    for (int i = 0; i < n; ++i) {
        prf[i + 1] = prf[i] + a[i];
    }
    auto sum = [&](int l, int r) -> LL {
        return prf[r + 1] - prf[l];
    };

    vector<vector<LL>> dp(n, vector<LL>(n));
    vector<vector<int>> opt(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0;
        opt[i][i] = i;
    }
    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i+l <= n; ++i) {
            int j = i + l - 1;
            dp[i][j] = INF;
            for (int k = opt[i][j-1]; k <= min(opt[i+1][j], n - 2); ++k) {
                if (dp[i][j] > dp[i][k] + dp[k+1][j]) {
                    dp[i][j] = dp[i][k] + dp[k+1][j];
                    opt[i][j] = k;
                }
            }
            dp[i][j] += sum(i, j);
        }
    }

    cout << dp[0][n - 1] << "\n";
}
