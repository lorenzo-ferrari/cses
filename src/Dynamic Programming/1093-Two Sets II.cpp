#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    int sum = n * (n + 1) / 2;
    vector<vector<int>> dp(n + 1, vector<int> (sum + 1));
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        int cur = i * (i + 1) / 2;
        for (int j = 1; j <= cur; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= i)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % mod;
        }
    }

    cout << ((sum & 1) ? 0 : dp[n][sum / 2]) << "\n";
}
