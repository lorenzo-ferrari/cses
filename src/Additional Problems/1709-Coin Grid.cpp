#include "bits/stdc++.h"
using namespace std;
using LL = long long;

vector<vector<int>> adj;
vector<vector<int>> c;
vector<int> d;

int bfs(int s, int t, vector<int>& par) {
    fill(begin(par), end(par), -1);
    fill(begin(d), end(d), 0);
    queue<int> Q; Q.push(s);
    d[s] = 1;
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int u : adj[v]) {
            if (c[v][u] != 0 && d[u] == 0) {
                par[u] = v;
                d[u] = min(d[v], c[v][u]);
                Q.push(u);
            }
        }
    }
    return d[t];
}

int maxflow(int n, int s, int t) {
    d.resize(n);
    vector<int> par(n);
    int flow = 0;
    int new_flow;
    while (new_flow = bfs(s, t, par)) {
        flow += new_flow;
        int cur = t;
        while (par[cur] != -1) {
            int prv = par[cur];
            c[prv][cur] -= new_flow;
            c[cur][prv] += new_flow;
            cur = prv;
        }
    }
    return flow;
}

int main() {
    int n; cin >> n;
    vector<array<int, 2>> e;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char c; cin >> c;
            if (c == 'o') {
                e.push_back({i, j});
            }
        }
    }
    int nn = 2*n + 2;
    int s = 0;
    int t = nn - 1;

    adj.resize(nn);
    c.assign(nn, vector<int>(nn, 0));
    for (int i = 1; i <= n; ++i) {
        adj[s].push_back(i);
        adj[i].push_back(s);
        c[s][i] = 1;
    }
    for (int i = n+1; i <= 2*n; ++i) {
        adj[i].push_back(t);
        adj[t].push_back(i);
        c[i][t] = 1;
    }
    for (auto [a, b] : e) {
        adj[a].push_back(b+n);
        adj[b+n].push_back(a);
        c[a][b+n] = 1;
    }

    int flow = maxflow(nn, s, t);
    cout << flow << "\n";
    
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 0) {
            cout << "1 " << i << "\n";
        }
    }
    for (int i = n+1; i <= 2*n; ++i) {
        if (d[i] == 1) {
            cout << "2 " << i-n << "\n";
        }
    }
}
