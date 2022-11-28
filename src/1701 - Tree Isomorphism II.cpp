#include <bits/stdc++.h>
using namespace std;

map<vector<int>, int> hasher;

int hashify(vector<int> x) {
    sort(begin(x), end(x));
    if (!hasher[x]) {
        hasher[x] = hasher.size();
    }
    return hasher[x];
}

int hashTree(const vector<vector<int>>& adj, int v, int par) {
    vector<int> children;
    for (int u : adj[v]) {
        if (u == par) continue;
        children.push_back(hashTree(adj, u, v));
    }
    return hashify(children);
}

bool isomorph(const vector<vector<int>>& t1, const vector<vector<int>>& t2, int rt1 = 0, int rt2 = 0) {
    return hashTree(t1, rt1, -1) == hashTree(t2, rt2, -1);
}

vector<int> centroids(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> sz(n);
    auto dfs = [&](auto&& self, int v, int p) -> int {
        sz[v] = 1;
        for (int u : adj[v]) {
            if (u == p) continue;
            sz[v] += self(self, u, v);
        }
        return sz[v];
    };
    dfs(dfs, 0, -1);
    vector<int> ans;
    auto find = [&](auto&& self, int v, int p) -> void {
        bool good = (n - sz[v] <= n/2);
        for (int u : adj[v]) {
            if (u == p) continue;
            if (n - sz[u] <= n/2) {
                self(self, u, v);
            }
            if (sz[u] > n/2) {
                good = false;
            }
        }
        if (good) {
            ans.push_back(v);
        }
    };
    find(find, 0, -1);
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> t1(n);
    vector<vector<int>> t2(n);
    for (int i = 0, a, b; i < n-1; ++i) {
        cin >> a >> b; --a, --b;
        t1[a].push_back(b);
        t1[b].push_back(a);
    }
    for (int i = 0, a, b; i < n-1; ++i) {
        cin >> a >> b; --a, --b;
        t2[a].push_back(b);
        t2[b].push_back(a);
    }
    auto c1 = centroids(t1);
    auto c2 = centroids(t2);
    bool ans = false;
    for (int rt1 : c1) for (int rt2 : c2) {
        if (ans || isomorph(t1, t2, rt1, rt2)) {
            ans = true;
        }
    }
    cout << (ans ? "YES\n" : "NO\n");
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}

