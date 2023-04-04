/*
Task:              1675 Road Reparation
Sender:            lorenzo_ferrari
Submission time:   2022-11-17 16:46:38
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct Dsu {
    vector<int> p;
    Dsu(int n) : p(vector<int>(n)) {
        iota(begin(p), end(p), 0);
    }
    int find(int i) { return p[i] == i ? i : p[i] = find(p[i]); }
    bool onion(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        p[b] = a;
        return true;
    }
    int count() const {
        int ans = 0;
        for (int i = 0; i < (int)p.size(); ++i) {
            ans += (p[i] == i);
        }
        return ans;
    }
};

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<array<LL, 2>>> adj(n);
    for (LL i = 0, a, b, c; i < m; ++i) {
        cin >> a >> b >> c; --a, --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    LL ans = 0;
    int cnt = 0;

    Dsu dsu(n);
    for (int it = 1; it < 20; ++it) {
        vector<array<LL, 3>> me(n, {1LL<<50, -1});
        for (int i = 0; i < n; ++i) {
            int ii = dsu.find(i);
            for (const auto& [j, w] : adj[i]) {
                int jj = dsu.find(j);
                if (ii == jj) continue;
                if (w < me[ii][0]) {
                    me[ii] = {w, jj};
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i == dsu.find(i) && me[i][1] != -1) {
                if (dsu.onion(i, me[i][1])) {
                    ans += me[i][0];
                }
            }
        }
    }
    if (dsu.count() != 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans << "\n";
    }
}
