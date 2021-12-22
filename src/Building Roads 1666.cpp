#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector <vector<int>> graph(n + 1);
    vector <bool> vis(n + 1);

    for (int i = 0, a, b; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int prv = -1;
    queue <int> Q;
    vector <pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (prv != -1)
                ans.push_back({prv, i});
            prv = i;
            vis[i] = true;
            Q.push(i);
            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();
                for (int u : graph[v]) {
                    if (!vis[u]) {
                        vis[u] = true;
                        Q.push(u);
                    }                    
                }
            }
        }
    }

    printf("%d\n", (int)ans.size());
    for (auto x : ans) 
        printf("%d %d\n", x.first, x.second);
}
