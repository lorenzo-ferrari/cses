/*
Task:              1751 Planets Cycles
Sender:            lorenzo_ferrari
Submission time:   2021-06-19 18:47:09
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t(n + 1);
    vector<vector<int>> r(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        r[t[i]].push_back(i);
    }

    vector<int> l(n + 1);
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
                l[v] = 1;
                int a = t[v];
                while (a != v) {
                    c[a] = true;
                    ++l[v];
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
                    l[u] = l[v];
                    dfs2(u);
                }
        };

        for (int i = 1; i <= n; ++i) if (c[i]) d[i] = 0;
        for (int i = 1; i <= n; ++i) if (c[i]) dfs2(i);
    }

    for (int i = 1; i <= n; ++i) cout << d[i] + l[i] << " "; cout << "\n";
}
