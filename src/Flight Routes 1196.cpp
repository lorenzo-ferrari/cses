#include <set>
#include <queue>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;
#define F first
#define S second

int main() {
    int64_t n, m, k;
    scanf("%ld %ld %ld", &n, &m, &k);
    vector <vector<pair<int, int64_t>>> g(n + 1);
    for (int64_t i = 0, a, b, c; i < m; i++) {
        scanf("%ld %ld %ld", &a, &b, &c);
        g[a].push_back({b, c});
    }

    vector <int> vis(n + 1);
    vector <multiset<int64_t>> d(n + 1);
    d[1].insert(0);
    priority_queue <pair<int64_t, int>> Q;
    Q.push({0, 1});

    while (!Q.empty()) {
        int v = Q.top().S;
        int64_t c = -Q.top().F;
        Q.pop();
        
        if (vis[v] >= k)
            continue;
        vis[v]++;
        
        for (auto e : g[v]) {
            if (d[e.F].size() < k || d[e.F].upper_bound(c + e.S) != d[e.F].end()) {
                if (d[e.F].size() == k) {
                    auto it = d[e.F].end();
                    d[e.F].erase(--it);
                }

                d[e.F].insert(e.S + c);
                Q.push({-(e.S + c), e.F});
            }
        }
    }

    //assert(d[n].size() == k);

    //for (auto x : d) {
    //   for (int y : x)
    //        printf("%d ", y);
    //    printf("\n");
    //}

    for (int64_t x : d[n])
        printf("%ld ", x);
    printf("\n");
}
