#include <queue>
#include <vector>
#include <iostream>
#pragma GCC optimize ("O3")
#define F first
#define S second
using namespace std;

// what is the minimum price of such a route?
// how many minimum-price routes are there? (modulo 1e9+7)
// what is the minimum number of flights in a minimum-price route?
// what is the maximum number of flights in a minimum-price route? 

const int64_t mod = 1e9 + 7;
const int64_t INF = 1e15;

vector <bool> vs;
vector <int64_t> ord;
vector <vector<int64_t>> to;

void dfs(int64_t v) {
    vs[v] = true;
    for (int64_t u : to[v])
        if (!vs[u])
            dfs(u);
    ord.push_back(v);
}

int64_t calculate_routes(int64_t s, int64_t e) {
    dfs(s);

    vector <int64_t> r(vs.size(), 0);
    r[e] = 1;
    for (int64_t v : ord) {
        for (int64_t u : to[v]) {
            r[v] += r[u];
        }
        r[v] %= mod;
    }

    return r[s];    
}

int32_t main() {
    int64_t n, m;
    scanf("%ld%ld", &n, &m);

    vector <bool> vis(n + 1);
    vector <vector<pair<int64_t, int64_t>>> g(n + 1);

    for (int64_t i = 0, u, v, w; i < m; i++) {
        scanf("%ld%ld%ld", &u, &v, &w);
        g[u].push_back({v, w});
    }

    vector <int64_t> d(n + 1, INF);
    vector <int64_t> mn(n + 1, -1);
    vector <int64_t> mx(n + 1, -1);
    
    d[1] = 0;
    mn[1] = 0;
    mx[1] = 0;

    vs.resize(n + 1);
    to.resize(n + 1);

    priority_queue <pair<int64_t, int64_t>> Q;
    Q.push({0, 1});
    while (!Q.empty()) {
        int64_t v = Q.top().S;
        int64_t dst = -Q.top().F;

        Q.pop();

        if (vis[v])
            continue;
        vis[v] = true;

        for (auto e : g[v]) {
            if (d[v] + e.S < d[e.F]) {
                to[e.F].clear();
                to[e.F].push_back(v);
                d[e.F] = d[v] + e.S;
                mn[e.F] = mn[v] + 1;
                mx[e.F] = mx[v] + 1;

                Q.push({-d[e.F], e.F});
            }
            else if (d[v] + e.S == d[e.F]) {
                to[e.F].push_back(v);
                mn[e.F] = min(mn[v] + 1, mn[e.F]);
                mx[e.F] = max(mx[v] + 1, mx[e.F]);
            }
        }
    }

    int64_t c = calculate_routes(n, 1);

    // for (int i = 1; i <= n; i++)
    //     printf("%d: %ld %ld %ld %ld\n", i, d[i], c[i], mn[i], mx[i]);

    printf("%ld %ld %ld %ld\n", d[n], c, mn[n], mx[n]);
}
