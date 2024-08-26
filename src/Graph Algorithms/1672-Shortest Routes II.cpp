#include <vector>
#include <assert.h>
#include <iostream>
using namespace std;
#define MAXN 501
#define int long long

const int INF = 1e15;

int32_t main() {
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int n, m, q;
    scanf("%lld %lld %lld", &n, &m, &q);
    int d[MAXN][MAXN];
    for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) d[i][j] = ((i != j) ? INF : 0);

    for (int i = 0, u, v, w; i < m; i++) {
        scanf("%lld %lld %lld", &u, &v, &w);
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    
    for (int i = 0, v, u; i < q; i++) {
        scanf("%lld %lld", &v, &u);
        printf("%lld\n", ((d[v][u] == INF) ? -1 : d[v][u]));
    }
}