#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> s(n);
    vector<vector<int>> adj(n);
    for (int i = 1, par; i < n; ++i) {
        cin >> par; --par;
        adj[par].push_back(i);
    }

    auto solve = [&](auto&& self, int v) -> void {
        s[v] = 1;
        for (int u : adj[v]) {
            self(self, u);
            s[v] += s[u];
        }
    };

    solve(solve, 0);

    for (int i = 0; i < n; ++i) {
        cout << s[i] - 1 << " ";
    }
    cout << "\n";
}
