#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;

    vector<int> d(n + 1);
    vector<set<int>> g(n + 1);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        g[a].insert(b);
        ++d[a];
        --d[b];
    }
 
    function<void()> ret = [&]() {
        cout << "IMPOSSIBLE" << "\n";
        exit(0);
    };

    if (d[1] ^ 1 || d[n] ^ -1)
        ret();
    for (int i = 2; i < n; ++i)
        if (d[i])
            ret();

    vector<int> ans;
    function<void(int)> find_euler_cycle = [&](int v) {
        while (!g[v].empty()) {
            int u = *g[v].begin();
            g[v].erase(u);
            find_euler_cycle(u);
        }
        ans.push_back(v);
    };
 
    g[n].insert(1);
    find_euler_cycle(1);
    reverse(ans.begin(), ans.end());
    ans.pop_back();

    if (ans.size() ^ (m + 1)) ret();

    int s;
    for (s = 0; s <= m; ++s)
        if (ans[s] == 1 && ans[(s + m) % (m + 1)] == n)
            break;

    for (int i = s; i <= m; ++i) cout << ans[i] << " ";
    for (int i = 0; i <  s; ++i) cout << ans[i] << " ";
    cout << "\n";
}
