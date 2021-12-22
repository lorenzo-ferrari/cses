#include <bits/stdc++.h>
using namespace std;

const int N = 500;

int c[N][N];
vector<int> g[N];

int bfs(int s, int e, vector<int>& p) {
    fill(p.begin(), p.end(), -1);
    queue<pair<int, int>> Q;
    Q.push({s, 1e9});
    while (!Q.empty()) {
        int v = Q.front().first;
        int flow = Q.front().second;
        Q.pop();

        for (int& u : g[v]) {
            if (c[v][u] && p[u] == -1) {
                p[u] = v;
                int new_flow = min(flow, c[v][u]);
                if (u == e)
                    return new_flow;
                Q.push({u, new_flow});
            }
        }
    }
    return 0;
}

int maxflow(int n, int s, int e) {
    vector<int> p(n);
    int flow = 0;
    int new_flow;
    while (new_flow = bfs(s, e, p)) {
        flow += new_flow;
        int cur = e;
        while (cur != s) {
            int prv = p[cur];
            c[prv][cur] -= new_flow;
            c[cur][prv] += new_flow;
            cur = prv;
        }
    }
    return flow;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        c[a][b] = 1;
        c[b][a] = 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int flow = maxflow(n, 0, n - 1);

    function<void(int, vector<bool>&)> dfs = [&](int v, vector<bool>& r) {
        r[v] = true;
        for (int& u : g[v])
            if (c[v][u] && !r[u])
                dfs(u, r);
    };
    vector<bool> rs(n);
    dfs(0, rs);

    cout << flow << "\n";
    for (int i = 0; i < n; ++i)
        for (int& u : g[i])
            if (rs[i] && !rs[u])
                cout << i + 1 << " " << u + 1 << "\n"; }

