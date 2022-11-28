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
    bool ans = hashTree(t1, 0, -1) == hashTree(t2, 0, -1);
    cout << (ans ? "YES\n" : "NO\n");
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}

