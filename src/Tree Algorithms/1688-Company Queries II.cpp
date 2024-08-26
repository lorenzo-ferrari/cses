#include <bits/stdc++.h>
using namespace std;

constexpr int LOG = 18;
constexpr int N = 2e5 + 5;

int up[N][LOG];
// up[i][j] = "dove finisco dopo 2^j salti?"
// up[i][0] = par[i]
// up[i][j] = up[ up[i][j-1] ][j-1], 2^j = 2^{j-1} + 2^{j-1}
int dep[N];
vector<int> adj[N];

int lift(int v, int k) {
    for (int i = 0; i < LOG; ++i) {
        if (v == -1) {
            break;
        }
        if (k & (1 << i)) { // 2^i sta nella rappr. binaria di k
            v = up[v][i];
        }
    }
    return v;
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) {
        swap(a, b);
    }
    // (wlog), dep[a] <= dep[b]
    b = lift(b, dep[b] - dep[a]);
    
    if (a == b) {
        return a;
    }
    
    for (int j = LOG-1; j >= 0; --j) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    assert(up[a][0] == up[b][0]);
    return up[a][0];
}

void dfs(int v) {
    for (int u : adj[v]) {
        dep[u] = dep[v] + 1;
        dfs(u);
    }
}

int main() {
    int n; cin >> n;
    int q; cin >> q;
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i]; --p[i];
        adj[p[i]].push_back(i);
    }
    p[0] = -1;

    dep[0] = 0;
    dfs(0);

    for (int i = 0; i < n; ++i) {
        up[i][0] = p[i];
    }
    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            if (up[i][j-1] == -1) {
                up[i][j] = -1;
            } else {
                up[i][j] = up[ up[i][j-1] ][j-1];
            }
        }
    }

    for (int i = 0, a, b; i < q; ++i) {
        cin >> a >> b; --a, --b;
        int ans = lca(a, b);
        cout << ans+1 << "\n";
    }
}
