/*
Task:              1679 Course Schedule
Sender:            lorenzo_ferrari
Submission time:   2020-11-01 19:12:53
Language:          C++17
Result:            ACCEPTED
*/
#include <vector>
#include <iostream>

using namespace std;

int n, m;
vector <int> ans;
vector <int> deg;
vector <vector<int>> g;

void dfs(int v) {
    --deg[v]; //make it != 0
    ans.push_back(v);
    for (int u : g[v])
        if (--deg[u] == 0)
            dfs(u);
}

int main() {
    scanf("%d %d", &n, &m);
    g.resize(n + 1);
    deg.resize(n + 1);

    for (int i = 0, a, b; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        deg[b]++;
    }

    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            dfs(i);
    
    if ((int)ans.size() != n) {
        printf("IMPOSSIBLE\n");
    }
    /*else*/ {
        for (int i : ans)
            printf("%d ", i);
    }
}