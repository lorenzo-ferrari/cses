#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int x; cin >> x;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> dp(x+1, 1e9); dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = v[i]; j <= x; ++j) {
            dp[j] = min(dp[j], dp[j - v[i]] + 1);
        }
    }
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << "\n";
}

