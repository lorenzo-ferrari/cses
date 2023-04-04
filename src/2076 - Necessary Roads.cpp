/*
Task:              2076 Necessary Roads
Sender:            lorenzo_ferrari
Submission time:   2023-04-02 11:14:01
Language:          C++17
Result:            ACCEPTED
*/
#include "bits/stdc++.h"
using namespace std;
using LL = long long;

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> adj(n);
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b; --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> dep(n, -1); dep[0] = 0;
    vector<int> dp(n, n); dp[0] = 0;
    vector<vector<int>> tree(n);
    vector<int> par(n);
    auto dfs = [&](auto&& self, int v, int p) -> void {
        dp[v] = dep[v];
        par[v] = p;
        for (int u : adj[v]) {
            if (u == p) continue;
            if (dep[u] == -1) {
                dep[u] = dep[v] + 1;
                tree[v].push_back(u);
                self(self, u, v);
                dp[v] = min(dp[v], dp[u]);
            } else {
                dp[v] = min(dp[v], dep[u]);
            }
        }
    };
    dfs(dfs, 0, -1);
    vector<array<int, 2>> ans;
    for (int i = 1; i < n; ++i) {
        if (dp[i] == dep[i]) {
            ans.push_back({i, par[i]});
        }
    }
    cout << ans.size() << "\n";
    for (auto [i, j] : ans) {
        cout << i+1 << " " << j+1 << "\n";
    }
}
