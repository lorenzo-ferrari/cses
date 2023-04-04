/*
Task:              1667 Message Route
Sender:            lorenzo_ferrari
Submission time:   2020-10-28 10:43:08
Language:          C++17
Result:            ACCEPTED
*/
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 2147483647

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector <vector<int>> graph(n + 1);
    vector <int> d(n + 1, INF), tramite(n + 1, -1);

    for (int i = 0, a, b; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int prv = -1;
    d[1] = 1;
    queue <int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int u : graph[v]) {
            if (d[u] > d[v] + 1) {
                tramite[u] = v;
                d[u] = d[v] + 1;
                Q.push(u);
            } 
        }
    }

    if (d[n] != INF) {
        printf("%d\n", d[n]);
        vector <int> ans;
        int v = n;
        ans.push_back(n);
        while(v != 1) {
            ans.push_back(tramite[v]);
            v = tramite[v];
        }
        reverse(ans.begin(), ans.end());
        for (int u : ans) printf("%d ", u);
        printf("\n");
    }
    else {
        printf("IMPOSSIBLE\n");
    }
}