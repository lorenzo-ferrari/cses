#include "bits/stdc++.h"
using namespace std;
using LL = long long;

vector<int> kmp(string s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) {
            j = pi[j - 1];
        }
        pi[i] = j + (s[j] == s[i]);
    }

    return pi;
}

static constexpr int mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int m = s.size();

    vector<array<int, 26>> tr(m+1);
    for (int i = 0; i < m; ++i) {
        auto t = s.substr(0, i);
        for (int c = 0; c < 26; ++c) {
            if (c == s[i]) continue;
            t.push_back('A'+c);
            tr[i][c] = kmp(t)[i];
            t.pop_back();
        }
    }

    vector<vector<LL>> dp(n+1, vector<LL>(m+1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int mat = 0; mat < m; ++mat) {
            for (int c = 0; c < 26; ++c) {
                if ('A'+c == s[mat]) continue;
                dp[i][tr[mat][c]] += dp[i-1][mat];
                dp[i][tr[mat][c]] %= mod;
            }
            dp[i][mat+1] += dp[i-1][mat];
            dp[i][mat+1] %= mod;
        }
        dp[i][m] += 26 * dp[i-1][m];
        dp[i][m] %= mod;
    }

    cout << dp[n][m] << "\n";
}
