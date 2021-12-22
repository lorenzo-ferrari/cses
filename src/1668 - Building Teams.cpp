#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector <vector<int>> graph(n + 1);
    vector <int> g(n + 1);

    for (int i = 0, u, v; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);        
    }
    
    queue <int> Q;
    for (int i = 1; i <= n; i++) {
        if (!g[i]) {
            Q.push(i);
            g[i] = 1;
            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();
                for (int u : graph[v]) {
                    if (g[u] && g[v] == g[u]) {
                        printf("IMPOSSIBLE\n");
                        return 0;
                    }
                    if (!g[u]) {
                        g[u] = (g[v] & 1) + 1;
                        Q.push(u);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", g[i]);
    printf("\n");
}
