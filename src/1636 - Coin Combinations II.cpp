/*
Task:              1636 Coin Combinations II
Sender:            lorenzo_ferrari
Submission time:   2021-06-21 15:31:51
Language:          C++17
Result:            ACCEPTED
*/
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
