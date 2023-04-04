/*
Task:              1683 Planets and Kingdoms
Sender:            lorenzo_ferrari
Submission time:   2021-06-19 20:39:30
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int n, m;
vector<vector<int>> g;
vector<vector<int>> r;

int C;
vector<int> c;
vector<int> o;
vector<bool> vis;

void dfs1(int v) {
    vis[v] = true;
    for (int u : g[v])
        if (!vis[u])
            dfs1(u);
    o.push_back(v);
}

void dfs2(int v) {
    vis[v] = true;
    c[v] = C;
    for (int u : r[v])
        if (!vis[u])
         dfs2(u);
}

int32_t main() {
    cin >> n >> m;
    g.resize(n + 1);
    r.resize(n + 1);
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        r[b].push_back(a);
    }

    c.resize(n + 1);
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs1(i);
    vis.assign(n + 1, 0);
    reverse(o.begin(), o.end());
    for (int i : o)
        if (!vis[i]) {
            C++;
            dfs2(i);
        }

    cout << C << "\n";
    for (int i = 1; i <= n; ++i)
        cout << c[i] << " ";
    cout << "\n";
}
