#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int n, q;
int t[N<<1];

void build()
{
    for(int i = n-1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

int query(int l, int r)
{
    int res = 2e9;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if(l&1) res = min(res, t[l++]);
        if(r&1) res = min(res, t[--r]);
    }

    return res;
}

int main()
{
    //scanf("%d", &n);
    //scanf("%d", &q);
    cin >> n >> q;
    int l, r;

    for(int i = 0; i < n; i++) cin >> t[n+i];//scanf("%d", t+n+i);

    build();

    for(int i = 0; i < q; i++)
    {
        cin >> l >> r;
        //scanf("%d", &l);
        //scanf("%d", &r);
        cout << query(l-1, r) << "\n";
        //printf("%d\n", query(l, r));
    }
}

