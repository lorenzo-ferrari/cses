#include <bits/stdc++.h>
using namespace std;

struct Dsu {
    int n;
    vector<int> par;

    Dsu(int _n) : n(_n), par(n) {
        iota(begin(par), end(par), 0);
        // for (int i = 0; i < n; ++i) {
        //    par[i] = i;
        // }
    }

    int find(int v) {
        // if (p[v] == v) {
        //     return v;
        // } else {
        //     return par[v] = find(par[v]);
        // }
        return par[v] == v ? v : par[v] = find(par[v]);
    }

    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        } else {
            par[b] = a;
            return true;
        }
    }
};

constexpr array<int, 4> dx{+1,-1, 0, 0};
constexpr array<int, 4> dy{ 0, 0,+1,-1};

int main() {
    int n; cin >> n;
    int m; cin >> m;
 
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cin >> g[i][j];
    }

    auto tr = [&](int i, int j) -> int {
        return i * m + j;
    };

    int cc = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cc += (g[i][j] == '.');
    }

    Dsu dsu(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '#') continue;
            for (int _ = 0; _ < 4; ++_) {
                int ni = i+dx[_];
                int nj = j+dy[_];
                if (!(0 <= ni && ni <= n-1)) continue;
                if (!(0 <= nj && nj <= m-1)) continue;
                if (g[ni][nj] == '#') continue; // !

                cc -= dsu.merge(tr(i, j), tr(ni, nj));
            }
        }
    }

    cout << cc << "\n";
}
