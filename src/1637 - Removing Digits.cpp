/*
Task:              1637 Removing Digits
Sender:            lorenzo_ferrari
Submission time:   2021-06-21 15:35:45
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> d(int n) {
    vector<int> ans;
    while (n) {
        ans.push_back(n % 10);
        n /= 10;
    }
    return ans;
}


int main() {
    int n;
    cin >> n;

    const int INF = 1e9;

    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        auto x = d(i);
        for (int& j : x)
            dp[i] = min(dp[i], 1 + dp[i - j]);
    }

    cout << dp[n] << "\n";
}
