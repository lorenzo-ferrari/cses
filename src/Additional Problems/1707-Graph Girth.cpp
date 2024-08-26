#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<set<int>> g(n);
    vector<pair<int, int>> edgs(m);
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        edgs[i] = {a, b};
        g[a].insert(b);
        g[b].insert(a);
    }

    if (m == n - 1) {
        cout << -1 << "\n";
        return 0;
    }

    const int INF = 1e9;
    int ans = INF;
    vector<int> d(n);
    function<void(int)> bfs = [&](int a) {
        fill(d.begin(), d.end(), INF);
        queue<pair<int, int>> Q;
        
        d[a] = 0;
        Q.push({a, 0});

        while (!Q.empty()) {
            int v = Q.front().first;
            int t = Q.front().second;
            Q.pop();

            if (t >= ans - 1) return;

            for (int u : g[v])
                if (d[u] > d[v] + 1) {
                    d[u] = d[v] + 1;
                    Q.push({u, d[v]});
                }
        }
    };

    for (auto& [a, b] : edgs) {
        g[a].erase(b);
        g[b].erase(a);
        bfs(a);
        if (d[b] != INF)
            ans = min(ans, d[b] + 1);
        g[a].insert(b);
        g[b].insert(a);
    }
    cout << ans << "\n";
}
