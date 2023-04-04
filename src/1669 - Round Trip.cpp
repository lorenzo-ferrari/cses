/*
Task:              1669 Round Trip
Sender:            lorenzo_ferrari
Submission time:   2020-10-28 17:32:47
Language:          C++17
Result:            ACCEPTED
*/
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100001

int n, m;
int t[MAXN];
bool vis[MAXN], vis2[MAXN];
vector <int> graph[MAXN];

void semplifica (vector <int> &a) {
    int l = 0, r = a.size()-1;
    while (r - l > 4 && a[l + 1] == a[r - 1]) {
        l++;
        r--;
    }
    
    a = vector <int> (a.begin() + l, a.begin() + r + 1);

}

void look_for_cycle(int v) {
    //printf("%d\n", v);
    vis2[v] = true;
    queue <int> Q;
    Q.push(v);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int x : graph[u]) {
            if (x == t[u]) continue;
            if (!vis2[x]) {
                Q.push(x);
                vis2[x] = true;
                t[x] = u;
            }
            else {
                //printf("x: %d\nu: %d\n", x, u);
                vector <int> ans;
                while (u != v) {
                    ans.push_back(u);
                    u = t[u];
                }
                ans.push_back(v);
                reverse(ans.begin(), ans.end());
                while (x != v) {
                    ans.push_back(x);
                    x = t[x];
                }
                ans.push_back(v);

                semplifica(ans);

                printf("%d\n", (int)ans.size());
                for (auto y : ans) 
                    printf("%d ", y);
                printf("\n");
                exit(0);
            }
        }
    }
    exit(0);
}

void dfs(int v, int par) {
    for (int u : graph[v]) {
        if (u == par) continue;
        if (vis[u]) look_for_cycle(u);
        vis[u] = true;
        dfs(u, v);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i, 0);
        }
    }

    printf("IMPOSSIBLE\n");
}