#include <set>
#include <vector>
#include <iostream>
using namespace std;

int n, m;
vector <int> ans;
vector <set<int>> g;

void find_eulerian_cycle(int v) {
    while (g[v].size()) {
        int u = *g[v].begin();

        g[v].erase(u);
        g[u].erase(v);

        find_eulerian_cycle(u);
    }
    ans.push_back(v);
}

int main() {
    scanf("%d %d", &n, &m);
    g.resize(n + 1);

    for (int i = 0, u, v; i < m; i++) {
        scanf("%d %d", &u, &v);
        g[u].insert(v);
        g[v].insert(u);
    }

    for (int i = 1; i <= n; i++) {
        if (g[i].size() & 1) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }

    find_eulerian_cycle(1);

    if (ans.size() != m + 1) {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    for (int v : ans) {
        printf("%d ", v);
    }
}