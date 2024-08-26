// https://cses.fi/paste/4ef67f94bf7f80687e49c2/
#include <bits/stdc++.h>
using namespace std;

int best;
vector<int> d;
vector<vector<int>> adj;

void solve(int v, int par) {
    if (d[v] > d[best]) {
        best = v;
    }
    for (int u : adj[v]) {
        if (u == par) {
            continue;
        }
        d[u] = d[v] + 1;
        solve(u, v);
    }
}

int main() {
    int n; cin >> n;
    adj.resize(n);
    d.resize(n);
    for (int i = 0, a, b; i < n - 1; ++i) {
        cin >> a >> b; --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    d[0] = 0;
    solve(0, -1);
    // best è il più lontano da 0
    // -> è un estremo del diametro
    d[best] = 0;
    solve(best, -1);

    cout << d[best] << "\n";
}
