/*
Task:              1195 Flight Discount
Sender:            lorenzo_ferrari
Submission time:   2020-10-30 10:42:59
Language:          C++17
Result:            ACCEPTED
*/
#include <array>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
#define int int64_t

const int INF = 1e15;

int32_t main() {
    int n, m;
    scanf("%ld %ld", &n, &m);
    vector <vector<array<int, 2>>> graph(n + 1);
    vector <vector<int>> dist(n + 1, vector <int> (2, INF));
    vector <vector<bool>> vis(n + 1, vector <bool> (2));
    for (int i = 0, a, b, c; i < m; i++) {
        scanf("%ld %ld %ld", &a, &b, &c);
        graph[a].push_back({b, c});
    }

    dist[1][0] = 0;
    dist[1][1] = 0;
    priority_queue <array<int, 3>> Q;
    Q.push({0, 1, 0});
    while (!Q.empty()) {
        int d = -Q.top()[0];
        int v =  Q.top()[1];
        int k =  Q.top()[2];
        Q.pop();

        if (vis[v][k])
            continue;
        vis[v][k] = true;

        for (auto x : graph[v]) {
            if (dist[x[0]][k] > d + x[1]) {
                dist[x[0]][k] = d + x[1];
                Q.push({-dist[x[0]][k], x[0], k});
            }
            if (k == 0 && dist[x[0]][k + 1] > d + x[1] / 2) {
                dist[x[0]][k + 1] = d + x[1] / 2;
                Q.push({-dist[x[0]][k + 1], x[0], k + 1});                
            }
        }
    }

    printf("%ld\n", min(dist[n][0], dist[n][1]));
}