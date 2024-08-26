#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q, temp;
    cin >> n >> q;
    vector <long long> pref(n+1);
    
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        pref[i] = pref[i-1]+temp;
    }
    
    for(int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l-1] << "\n";
    }
    
}
