#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
const int INF = 1e9;

int n, m;
string a, b;
vector<vector<int>> dp;

int main() {
    cin >> a >> b;
    n = a.size();
    m = b.size();
    dp.assign(n + 1, vector<int> (m + 1, INF));

    for (int i = 0; i <= n; ++i) dp[i][m] = n - i;
    for (int i = 0; i <= m; ++i) dp[n][i] = m - i;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (a[i] == b[j])
                dp[i][j] = dp[i + 1][j + 1];
            else
                dp[i][j] = 1 + min(min(dp[i + 1][j + 1], dp[i + 1][j]), dp[i][j + 1]);
        }
    }

    cout << dp[0][0] << "\n";
}

