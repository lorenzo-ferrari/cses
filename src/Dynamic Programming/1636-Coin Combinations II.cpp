#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int& i : c)
        cin >> i;
    sort(c.begin(), c.end());
    vector<int> dp(x + 1);
    dp[0] = 1;
    for (int& i : c)
        for (int j = 0; j <= x - i; ++j) {
            dp[j + i] += dp[j];
            if (dp[j + i] >= mod)
                dp[j + i] -= mod;
        }
    cout << dp[x] << "\n";
}
