#include <queue>
#include <vector>
#include <iostream>
using namespace std;
#define F first
#define S second

int32_t main() {
    int64_t n, m;
    scanf("%ld%ld", &n, &m);
    vector <vector<pair<int64_t, int64_t>>> g(n + 1);

    for (int64_t i = 0, a, b, c; i < m; i++) {
        scanf("%ld%ld%ld", &a, &b, &c);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    queue <int> q;
    vector <bool> vs(n + 1);
    q.push(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto e : g[v]) {
            if (!vs[e.F]) {
                vs[e.F] = true;
                q.push(e.F);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vs[i]) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }

    const int64_t INF = 1e15;

    vector <bool> vis(n + 1);
    vector <int64_t> d(n + 1, INF);
    priority_queue <pair<int64_t, int64_t>> Q;

    d[1] = 0;
    Q.push({0, 1});
    while (!Q.empty()) {
        int v =  Q.top().S;

        Q.pop();

        if (vis[v])
            continue;
        vis[v] = true;

        for (auto e : g[v]) {
            if (!vis[e.F] && d[e.F] > e.S) {
                d[e.F] = e.S;
                Q.push({-d[e.F], e.F});
            }
        }
    }

    int64_t tot = 0;
    for (int i = 1; i <= n; i++)
        tot += d[i];
    
    printf("%ld\n", tot);
}
