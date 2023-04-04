/*
Task:              1638 Grid Paths
Sender:            lorenzo_ferrari
Submission time:   2021-06-21 15:42:19
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> g(n + 1, vector<bool> (n + 1));
    vector<vector<int>> dp(n + 1, vector<int> (n + 1));

    char c;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> c;
            g[i][j] = (c == '.');
        }

    dp[1][1] = g[1][1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 && j == 1 || !g[i][j])
                continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        }
    }

    cout << dp[n][n] << "\n";
}
