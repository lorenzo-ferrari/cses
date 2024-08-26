#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    vector <int> pref(n+1);

    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        pref[i] = pref[i-1]^temp;
    }

    for(int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << (pref[b]^pref[a-1]) << "\n";
    }
}