#include <map>
#include <array>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define int int64_t

int n, m;
vector <int> d, a, b, c, t;
vector <bool> vis;

void print_cycle(int x) {
    vector <int> st;
    st.push_back(x);
    
    map <int, bool> mp;
    mp[x] = true;
    while (!mp[t[x]]) {
        st.push_back(t[x]);
        mp[x = t[x]] = true;
    }
    st.push_back(t[x]);

    int i = 0;
    while (st[i] != st.back()) i++;

    reverse(st.begin() + i, st.end());

    printf("YES\n");
    while (i < st.size())
        printf("%ld ", st[i++]);

    exit(0);
}

void bellman_ford(int x) {
    vis[x] = true;

    for (int j = 0; j < n - 1; j++) {
        bool any = false;
        for (int i = 0; i < m; i++) {
            if (vis[a[i]] && (!vis[b[i]] || d[b[i]] > d[a[i]] + c[i])) {
                d[b[i]] = d[a[i]] + c[i];
                t[b[i]] = a[i];
                vis[b[i]] = true;
                any = true;
            }
        }
        if (!any)
            break;
    }

    for (int i = 0; i < m; i++) {
        if (vis[a[i]] && (!vis[b[i]] || d[b[i]] > d[a[i]] + c[i])) {
            d[b[i]] = d[a[i]] + c[i];
            t[b[i]] = a[i];
            vis[b[i]] = true;

            print_cycle(b[i]);
        }
    }
}

int32_t main() {
    scanf("%ld %ld", &n, &m);
    vis.resize(n + 1);
    d.resize(n + 1);
    t.resize(n + 1);
    a.resize(m);
    b.resize(m);
    c.resize(m);
    
    for (int i = 0; i < m; i++)
        scanf("%ld %ld %ld", &a[i], &b[i], &c[i]);
    
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            bellman_ford(i);

    printf("NO\n");
}