#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int n, q;
int64_t t[N<<1];

void build()
{
    for(int i = n-1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int l, int r, int64_t value)
{
    for(r += n, l += n; l < r; l>>=1, r >>=1)
    {
        if(l&1) t[l++] += value;
        if(r&1) t[--r] += value;
    }
}

int64_t query(int p)
{
    int64_t res = 0;
    for(p += n; p > 0; p>>=1) res += t[p];
    return res;
}

int main()
{
/*    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
*/
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%ld", t+n+i);

    for(int i = 0; i < q; i++)
    {
        int type;
        scanf("%d", &type);

        if(type == 1)
        {
            int64_t a, b, u;
            scanf("%ld %ld %ld", &a, &b, &u);
            modify(a-1, b, u);
        }
        else if(type == 2)
        {
            int64_t k;
            scanf("%ld", &k);
            printf("%ld\n", query(k-1));
        }
    }
}
