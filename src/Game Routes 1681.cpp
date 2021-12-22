#include <vector>
#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

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
    dp.resize(n + 1);

    for (int i = 0, a, b; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
    }

    dfs(1);

    dp[n] = 1;
    for (int i = 0; i < st.size(); i++) {
        for (int u : g[st[i]]) {
            dp[st[i]] += dp[u];
            dp[st[i]] %= mod;
        }
    }
    
    printf("%d\n", dp[1]);
}
