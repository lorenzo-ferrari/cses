#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n; cin >> n;
    vector<int> x(n);
    for (int& i : x)
        cin >> i;
    vector<vector<int>> dp(n + 1, vector<int> (n + 1));
    for (int i = 0; i < n; ++i) {
        dp[i][1] = x[i];
    }
    vector<int> p(n + 1);
    for (int i = 0; i < n; ++i)
        p[i + 1] = p[i] + x[i];
    auto sum = [&](int l, int r) {
        return p[r] - p[l]; // [l, r)
    };
    for (int j = 2; j <= n; ++j) {
        for (int i = 0; i <= n - j; ++i) {
            int s = sum(i, i + j);
            dp[i][j] = s - min(dp[i + 1][j - 1], dp[i][j - 1]);
        }
    }
    cout << dp[0][n] << "\n";
}
