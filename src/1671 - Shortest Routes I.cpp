/*
Task:              1671 Shortest Routes I
Sender:            lorenzo_ferrari
Submission time:   2020-10-29 19:45:13
Language:          C++17
Result:            ACCEPTED
*/
#include <array>
#include <queue>
#include <vector>
#include <iostream>
#pragma GCC optimize ("O3")
using namespace std;
#define F first
#define S second
#define int long long
#define INF (int)1e15
#define MAXN 100001

inline int get_int() {
    int n = 0;
    char c = getchar_unlocked();
    while (c >= '0') {
        n = (n << 3) + (n << 1) + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

inline void print(int n) {
    int i = 0;
    char S[20];
    if (n == 0) {
        putchar_unlocked('0');
        putchar_unlocked(' ');
        return;
    }
    while (n) {
        S[i++] = n % 10 + '0';
        n /= 10;
    }
    while (--i >= 0)
        putchar_unlocked(S[i]);
    putchar_unlocked(' ');
}

int32_t main() {
    int n = get_int();
    int m = get_int();
    //scanf("%lld %lld", &n, &m);
    vector <pair<int, int>> graph[MAXN];
    bool vis[MAXN]{};
    int d[MAXN];
    fill(d, d + n + 1, INF);

    for (int i = 0, u, v, w; i < m; i++) {
        //scanf("%lld %lld %lld", &u, &v, &w);
        u = get_int();
        v = get_int();
        w = get_int();
        graph[u].push_back({v, w});
    }

    d[1] = 0;
    priority_queue <pair<int, int>> Q;
    Q.push({0, 1});
    while (!Q.empty()) {
        int v = Q.top().S;
        int p =-Q.top().F;
        Q.pop();

        if (vis[v])
            continue;
        vis[v] = true;

        for (auto &u : graph[v]) {
            if (d[u.F] > p + u.S) {
                d[u.F] = p + u.S;
                Q.push({-d[u.F], u.F});
            }
        }
    }

    for (int i = 1; i <= n; i++)
        print(d[i]);
}