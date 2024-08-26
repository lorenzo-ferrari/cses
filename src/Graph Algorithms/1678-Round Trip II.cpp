#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

const int N = 1e5 + 5;

int s[N], p[N];
vector<int> g[N];

void dfs(int v) {
    s[v] = 1;
    for (int u : g[v]) {
        if (s[u] == 0) {
            p[u] = v;
            dfs(u);
        }
        else if (s[u] == 1) {
            vector<int> ans(1,u);
            while (v != u) {
                ans.push_back(v);
                v = p[v];
            }
            ans.push_back(u);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (int& i : ans)
                cout << i << " ";
            cout << "\n";
            exit(0);
        }
    }
    s[v] = 2;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i)
        if (!s[i])
            dfs(i);
    
    cout << "IMPOSSIBLE" << "\n";
}
