/*
Task:              1673 High Score
Sender:            lorenzo_ferrari
Submission time:   2020-10-30 10:23:52
Language:          C++17
Result:            ACCEPTED
*/
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
#define int int64_t

const int INF = -1000000000000000;

vector <vector<int>> graph;

void bfs(int n, vector <bool> &revVis) {
    vector <bool> vis(graph.size());
    revVis[n] = true;
    queue <int> Q;
    Q.push(n);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int u : graph[v]) {
            if (!revVis[u]) {
                revVis[u] = true;
                Q.push(u);
            }
        }
    }
}

int32_t main() {
    int n, m;
    scanf("%ld %ld", &n, &m);
    graph.resize(n + 1);
    vector <int> d(n + 1, INF);
    vector <bool> vis(n + 1), revVis(n + 1);
    vector <int> a(m), b(m), w(m);
    for (int i = 0; i < m; i++) {
        scanf("%ld %ld %ld", &a[i], &b[i], &w[i]);
        graph[b[i]].push_back(a[i]);
    }

    bfs(n, revVis);

    d[1] = 0;
    vis[1] = true;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (d[a[j]] != INF && (!vis[b[j]] || d[b[j]] < d[a[j]] + w[j])) {
                d[b[j]] = d[a[j]] + w[j];
                vis[b[j]] = 1;
            }
        }
    }
    
    bool cycle = false;
    for (int i = 0; i < m; i++) {
        if (d[a[i]] != INF && d[b[i]] < d[a[i]] + w[i] && revVis[b[i]]) {
            cycle = true;
            break;
        }
        if (d[a[i]] != INF)
            d[b[i]] = max(d[b[i]], d[a[i]] + w[i]);            
    }
    

    if (cycle) {
        printf("%d\n", -1);
    } else {
        printf("%ld\n", d[n]);
    }
    //for (int i = 1; i <= n; i++) printf("%ld ", d[i]); printf("\n");
}