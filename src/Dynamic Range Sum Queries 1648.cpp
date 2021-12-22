#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int n, q;
int64_t t[N<<1];

void build() //build the tree
{
    for(int i = n-1; i > 0; --i) t[i] = t[i<<1]+t[i<<1|1];
}

void modify(int p, int value) //set value at position p
{
    for(t[p+=n] = value; p > 1; p>>=1) t[p>>1] = t[p] + t[p^1];
}

int64_t query(int l, int r) //sum in interval [l, r)
{
    int64_t res = 0;
    for(l += n, r += n; l < r; l >>=1, r >>= 1)
    {
        if(l&1) res += t[l++];
        if(r&1) res += t[--r];
    }

    return res;
}

int main()
{
    cin >> n >> q;
    for(int i = 0; i < n; ++i)scanf("%ld", t + n + i);
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
