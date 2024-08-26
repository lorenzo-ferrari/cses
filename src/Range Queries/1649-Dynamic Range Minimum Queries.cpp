#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int n, q;
int t[N<<1];

void build()
{
    for(int i = n-1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

void modify(int p, int value)
{
    for(t[p += n] = value; p > 0; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

int query(int l, int r)
{
    int res = 1e9;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if(l&1) res = min(res, t[l++]);
        if(r&1) res = min(res, t[--r]);
    }

    return res;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for(int i = 0; i < n; ++i) scanf("%d", t + n + i);
    build();
    int type, a, b;
    for(int i = 0; i < q; i++)
    {
        cin >> type >> a >> b;
        if(type == 1)
            modify(a-1, b);
        else
            cout << query(a-1, b) << "\n";
    }
}