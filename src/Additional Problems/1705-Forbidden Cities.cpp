#include "bits/stdc++.h"
using namespace std;
using LL = long long;

static constexpr int LOG = 18;

struct SolveTree {
    struct nd {
        int to{0};
        int mn{0};
    };
    nd join(nd a, nd b) {
        return {b.to, min(a.mn, b.mn)};
    }
    int n;
    vector<int> dep;
    vector<int> low;
    vector<vector<int>> adj;
    vector<array<nd, LOG>> up;
    SolveTree(int _n, vector<vector<int>> _adj, vector<int> _low) : n(_n), dep(n), low(_low), adj(_adj), up(n) {
        dfs(0, 0);
        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                up[i][j] = join(up[i][j-1], up[up[i][j-1].to][j-1]);
            }
        }
    }

    void dfs(int v, int p) {
        up[v][0] = {p, low[v]};
        for (int u : adj[v]) {
            if (u == p) continue;
            dep[u] = dep[v] + 1;
            dfs(u, v);
        }
    }

    int lca(int a, int b) {
        if (dep[b] < dep[a]) {
            swap(a, b);
        }
        int k = dep[b] - dep[a];
        for (int i = 0; i < LOG; ++i) {
            if (k & (1 << i)) {
                b = up[b][i].to;
            }
        }
        if (a == b) {
            return a;
        }
        for (int i = LOG-1; i >= 0; --i) {
            if (up[a][i].to != up[b][i].to) {
                a = up[a][i].to;
                b = up[b][i].to;
            }
        }
        return up[a][0].to;
    }

    int min_lift(int a, int k) {
        nd na{a, low[a]};
        for (int i = 0; i < LOG; ++i) {
            if (k & (1 << i)) {
                na = join(na, up[na.to][i]);
            }
        }
        return na.mn;
    }

    bool works(int a, int b, int c) {
        if (dep[c] < dep[lca(a, b)]) return true;
        if (lca(a, c) == c && min_lift(a, dep[a] - dep[c]) >= dep[c]) return false;
        if (lca(b, c) == c && min_lift(b, dep[b] - dep[c]) >= dep[c]) return false;
        return true;
    }
};

int main() {
    int n; cin >> n;
    int m; cin >> m;
    int q; cin >> q;
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

    SolveTree sol(n, tree, dp);
    for (int a, b, c; q--;) {
        cin >> a >> b >> c;
        --a, --b, --c;
        if (a == c || b == c) {
            cout << "NO\n";
        } else if (!art[c]) {
            cout << "YES\n";
        } else if (sol.works(a, b, c)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
