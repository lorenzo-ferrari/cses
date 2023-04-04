/*
Task:              1680 Longest Flight Route
Sender:            lorenzo_ferrari
Submission time:   2020-11-01 21:03:02
Language:          C++17
Result:            ACCEPTED
*/
#include <vector>
#include <iostream>
using namespace std;

const int INF = 1e9;

vector <int> t;
vector <int> dp;
vector <int> st;
vector <bool> vis;
vector <vector<int>> g;

void dfs(int v) {
    vis[v] = true;
    for (int u : g[v])
        if (!vis[u])
            dfs(u);

    st.push_back(v);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    g.resize(n + 1);
    t.resize(n + 1);
    vis.resize(n + 1);
    dp.assign(n + 1, -INF);

    for (int i = 0, a, b; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
    }

    dfs(1);

    dp[n] = 1;
    for (int i = 0; i < st.size(); i++) {
        int v = st[i], mx = -INF;
        for (int u : g[v]) {
            if (dp[u] > mx) {
                t[v] = u;
                mx = dp[u];
            }
        }
        if (mx != -INF) dp[v] = max(dp[v], 1 + mx);
    }

    if (!vis[n]) {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    printf("%d\n", dp[1]);
    int v = 1;
    while (v != 0) {
        printf("%d ", v);
        v = t[v];
    }
    printf("\n");
    //for (int i = 1; i <= n; i++) printf("%d\n", dp[i]);
}