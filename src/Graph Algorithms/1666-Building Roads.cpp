#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> adj(n);

    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b); // a->b
        adj[b].push_back(a); // b->a
    }

    // contiamo le componenti connesse
    vector<bool> vis(n, false);

    auto visita = [&](int radice) -> void {
        queue<int> Q;
        vis[radice] = true;
        Q.push(radice);

        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();

            // processiamo v
            for (int u : adj[v]) {
                if (vis[u]) continue;
                vis[u] = true;
                Q.push(u);
            }
        }
    };

    vector<int> cc;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) {
            continue;
        } else {
            visita(i);
            cc.push_back(i);
        }
    }

    cout << cc.size() - 1 << "\n";
    for (int i = 0; i < (int)cc.size() - 1; ++i) {
        cout << cc[i]+1 << " " << cc[i+1]+1 << "\n";
    }
}
