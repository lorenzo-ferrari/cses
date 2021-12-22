#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int& i : x)
        cin >> i;

    vector<vector<int>> dp(n, vector<int> (m + 2));
    for (int i = 1; i <= m; ++i)
        dp[0][i] = (!x[0] || i == x[0]);
    for (int i = 1; i < n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!x[i] || j == x[i])
                dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j]) % mod + dp[i-1][j+1]) % mod;
    int ans = 0;
    for (int i = 1; i <= m; ++i)
        ans = (ans + dp[n-1][i]) % mod;
    cout << ans << "\n";
}

