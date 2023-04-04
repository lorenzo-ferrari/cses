/*
Task:              1160 Planets Queries II
Sender:            lorenzo_ferrari
Submission time:   2021-06-19 18:26:44
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> p;
    dsu(int n) {
        p.resize(n);
        while (n--) p[n] = n;
    }
    int find_set(int v) {
        return p[v] == v ? v : p[v] = find_set(p[v]);
    }
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        p[b] = a;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    dsu uf(n + 1);
    vector<int> t(n + 1);
    vector<vector<int>> r(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        uf.union_set(i, t[i]);
        r[t[i]].push_back(i);
    }

    vector<int> l(n + 1);
    vector<int> p(n + 1);
    vector<int> d(n + 1, -1);
    vector<bool> c(n + 1, false);
    {
        vector<int> vis(n + 1, 0);
        int timer = 0;
        function<void(int)> dfs1 = [&](int v) {
            vis[v] = timer;
            if (vis[t[v]] == 0)
                dfs1(t[v]);
            else if (vis[t[v]] == timer) {
                c[v] = true;
                l[v] = p[v] = 1;
                int a = t[v];
                while (a != v) {
                    c[a] = true;
                    p[a] = ++l[v];
                    a = t[a];
                }
                a = t[v];
                while (a != v) {
                    l[a] = l[v];
                    a = t[a];
                }
            }
        };

        for (int i = 1; i <= n; ++i)
            if (!vis[i]) {
                ++timer;
                dfs1(i);
            }

        function<void(int)> dfs2 = [&](int v) {
            for (int u : r[v])
                if (d[u] == -1) {
                    d[u] = d[v] + 1;
                    dfs2(u);
                }
        };

        for (int i = 1; i <= n; ++i) if (c[i]) d[i] = 0;
        for (int i = 1; i <= n; ++i) if (c[i]) dfs2(i);
    }

    const int LOG = 18;
    vector<vector<int>> up(n + 1, vector<int> (LOG));
    for (int i = 1; i <= n; ++i)
        up[i][0] = c[i] ? i : t[i];
    for (int i = 1; i < LOG; ++i)
        for (int j = 1; j <= n; ++j)
            up[j][i] = up[up[j][i-1]][i-1];

    function<bool(int, int)> anc = [&](int a, int b) {
        if (d[a] < d[b]) return false;
        for (int i = LOG-1; i >= 0; --i)
            if ((d[a] - d[b]) & (1 << i))
                a = up[a][i];
        return a == b;
    };

    for (int a, b; q--;) {
        cin >> a >> b;
        if (uf.find_set(a) != uf.find_set(b))
            cout << -1 << "\n";
        else if (c[b])
            cout << d[a] + (p[b] - p[up[a][LOG-1]] + l[b]) % l[b] << "\n";
        else if (up[a][LOG-1] != up[b][LOG-1])
            cout << -1 << "\n";
        else if (anc(a, b))
            cout << d[a] - d[b] << "\n"; 
        else
            cout << -1 << "\n";
    }
}
