#include "bits/stdc++.h"
using namespace std;

static constexpr int N{512};
static constexpr int INF{1 << 30};

static vector<array<int, 2>> adj[N];
static int dist[N];
static int from[N];
static int flow[N];
static int c[N][N];

static void add_edge(int a, int b, int w) {
    c[a][b] += 1;
    adj[a].push_back({b,  w});
    adj[b].push_back({a, -w});
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
        for (auto [u, w] : adj[v]) {
            if (!c[v][u]) continue;
            int new_dist = d + w;
            int new_flow = min(flow[v], c[v][u]);
            if (dist[u] > new_dist) {
                dist[u] = new_dist;
                flow[u] = new_flow;
                from[u] = v;
                Q.push({u, dist[u]});
            }
        }
    }
    return flow[e] != 0;
}

static int MinCostMaxFlow(int s, int e, int k) {
    int cost = 0;
    while (k && spfa(s, e)) {
        int new_flow = flow[e];
        new_flow = min(new_flow, k);
        cost += dist[e] * new_flow;
        k -= new_flow;
        int cur = e;
        while (cur != s) {
            int prv = from[cur];
            c[prv][cur] -= new_flow;
            c[cur][prv] += new_flow;
            cur = prv;
        }
    }
    return k ? -1 : cost;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int w; cin >> w;
            add_edge(i, j+n, w);
        }
    }
    for (int i = 1; i <= n; ++i) {
        add_edge(0, i, 0);
        add_edge(i+n, 2*n+1, 0);
    }

    int ans = MinCostMaxFlow(0, 2*n+1, n);

    cout << ans << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << i << " ";
        for (int j = 1; j <= n; ++j) {
            if (!c[i][j+n]) {
                cout << j << "\n";
                break;
            }
        }
    }
}
