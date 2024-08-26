#include <algorithm>
#include <vector>

class cc {
    int n;
    std::vector<std::vector<int>> g;
    std::vector<std::vector<int>> r;
    std::vector<bool> vis;
    std::vector<int> c;
    std::vector<int> o;

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

public:
    int C = 0;
    cc (int n, std::vector<std::vector<int>>& g) : n(n), g(g) {
        r.resize(n);
        for (int i = 0; i < n; ++i)
            for (int u : g[i])
                r[u].push_back(i);

        vis.assign(n, false);
        for (int i = 0; i < n; ++i)
            if (!vis[i])
                dfs1(i);
        c.resize(n);
        vis.assign(n, false);
        reverse(o.begin(), o.end());
        for (int i : o) {
            if (!vis[i]) {
                dfs2(i);
                C++;
            }
        }
    }

    int size() {
        return C;
    }

    std::vector<std::vector<int>> cgraph() {
        std::vector<std::vector<int>> cg(C);
        for (int i = 0; i < n; ++i)
            for (int j : g[i])
                cg[c[i]].push_back(c[j]);
        return cg;
    }

    std::vector<std::vector<int>> comps() {
        std::vector<std::vector<int>> ans(C);
        for (int i = 0; i < n; ++i)
            ans[c[i]].push_back(i);
        return ans;
    }

    int operator [](int i) { return c[i]; }
};


#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>>& g, vector<int>& vis, vector<int>& o) {
    vis[v] = 1;
    for (int u : g[v])
        if (!vis[u])
            dfs(u, g, vis, o);
    vis[v] = 2;
    o.push_back(v);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> k(n);
    for (int& i : k)
        cin >> i;
    vector<vector<int>> g(n);
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        g[a-1].push_back(b-1);
    }

    cc c(n, g);
    int cn = c.size();
    auto cg = c.cgraph();
    vector<long long> ck(cn);
    for (int i = 0; i < n; ++i)
        ck[c[i]] += k[i];

    vector<int> o;
    vector<int> vis(cn);
    for (int i = 0; i < cn; ++i)
        if (!vis[i])
            dfs(i, cg, vis, o);
    vector<long long> dp(cn);
    for (int i : o) {
        for (int j : cg[i])
            dp[i] = max(dp[i], dp[j]);
        dp[i] += ck[i];
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}
