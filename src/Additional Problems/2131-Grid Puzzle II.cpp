#include "bits/stdc++.h"
using namespace std;

static constexpr int N{256};
static constexpr int INF{1 << 30};
 
struct Edge {
    int b;  // node
    int w;  // weight (cost)
    int c;  // capacity
    int oth;// idx of (b,a) in adj[b]
};
 
static vector<Edge> adj[N];
static int dist[N];
static int from[N];
static int flow[N];
 
static void add_edge(int a, int b, int w, int c) {
    int idxa = adj[a].size();
    int idxb = adj[b].size();
    adj[a].push_back({b, w, c, idxb});
    adj[b].push_back({a, -w, 0, idxa});
}
 
static bool spfa(int s, int e) {
    fill(dist, dist+N, INF);
    dist[s] = 0;
    flow[s] = INF;
    flow[e] = 0;
    queue<array<int, 2>> Q;
    Q.push({s, dist[s]});
    while (!Q.empty()) {
        auto [v, d] = Q.front();
        Q.pop();
        if (dist[v] < d) {
            continue;
        }
        for (auto [u, w, c, oth] : adj[v]) {
            if (!c) continue;
            int new_dist = d + w;
            int new_flow = min(flow[v], c);
            if (dist[u] > new_dist) {
                dist[u] = new_dist;
                flow[u] = new_flow;
                from[u] = oth;
                Q.push({u, dist[u]});
            }
        }
    }
    return flow[e] != 0;
}

static int MinCostMaxFlow(int s, int e, int k) {
    int cost = 0;
    while (k && spfa(s, e)) {
        int new_flow = min(k, flow[e]);
        cost += dist[e] * new_flow;
        k -= new_flow;
        int cur = e;
        while (cur != s) {
            int idx_ba = from[cur];
            int prv = adj[cur][idx_ba].b;
            int idx_ab = adj[cur][idx_ba].oth;
            adj[prv][idx_ab].c -= new_flow;
            adj[cur][idx_ba].c += new_flow;
            cur = prv;
        }
    }
    return k ? -1 : cost;
}
 
int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector c(n, vector<int>(n));
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    for (auto& x : c) for (auto& y : x) cin >> y;
    int sa = accumulate(begin(a), end(a), 0);
    int sb = accumulate(begin(b), end(b), 0);

    if (sa != sb) {
        cout << "-1\n";
        return 0;
    }

    int nn = 2 * n + 2;
    int src = 0;
    int snk = nn - 1;
    for (int i = 0; i < n; ++i) {
        add_edge(src, i+1, 0, a[i]);
        add_edge(i+n+1, snk, 0, b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            add_edge(i, j+n, -c[i-1][j-1], 1);
        }
    }

    int cost = MinCostMaxFlow(src, snk, sa);
    if (cost == -1) {
        cout << "-1\n";
    } else {
        vector cap(nn, vector<int>(nn));
        for (int i = 0; i < nn; ++i) {
            for (auto e : adj[i]) {
                cap[i][e.b] = e.c;
            }
        }
        cout << -cost << "\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << "X."[cap[i][j+n]];
            }
            cout << "\n";
        }
    }
}
