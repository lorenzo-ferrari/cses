/*
Task:              2077 Necessary Cities
Sender:            lorenzo_ferrari
Submission time:   2023-04-04 12:42:09
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
    vector<map<int, bool>> e(n);
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b; --a, --b;
        if (e[a][b]) continue;
        e[a][b] = e[b][a] = 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // articulation points
    vector<int> par(n);
    vector<int> dep(n, -1);
    vector<int> dp(n, 1e9);
    dep[0] = 0;
    vector<vector<int>> tree(n);
    auto dfs = [&](auto&& self, int v, int p) -> void {
        par[v] = p;
        dp[v] = dep[v];
        for (auto u : adj[v]) {
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
    vector<bool> art(n, false);
    if (count(begin(par), end(par), 0) != 1) {
        art[0] = true;
    }
    for (int i = 1; i < n; ++i) {
        if (tree[i].empty()) continue;
        int maxdp = 0;
        for (int j : tree[i]) {
            maxdp = max(maxdp, dp[j]);
        }
        art[i] = (maxdp >= dep[i]);
    }

    cout << count(begin(art), end(art), true) << "\n";
    for (int i = 0; i < n; ++i) {
        if (art[i]) {
            cout << i+1 << " ";
        }
    }
    cout << "\n";
}
