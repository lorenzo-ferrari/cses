#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr LL INF = 1e15;

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<array<LL, 2>>> adj(n);

    for (int i = 0, a, b, w; i < m; ++i) {
        cin >> a >> b >> w;
        --a, --b;
        adj[a].push_back({b, w}); // a->b
    }

    vector<LL> d(n, INF);
    priority_queue<array<LL, 2>> Q; // {-d[v], v}
    d[0] = 0;
    Q.push({-0, 0});
    
    while (!Q.empty()) {
        LL dv =-Q.top()[0];
        int v = Q.top()[1]; 
        Q.pop();

        if (dv > d[v]) {
            continue;
        }
        for (auto [u, w] : adj[v]) {
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                Q.push({-d[u], u});;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << d[i] << " ";
    }
    cout << "\n";
}
