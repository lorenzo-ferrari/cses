#include <bits/stdc++.h>
using namespace std;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int> (b + 1));

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j)
                continue;
            dp[i][j] = 1e9;
            for (int k = 1; k < i; ++k)
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
            for (int k = 1; k < j; ++k)
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
        }
    }

    cout << dp[a][b] << "\n";
}

