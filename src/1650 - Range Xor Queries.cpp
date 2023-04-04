/*
Task:              1650 Range Xor Queries
Sender:            lorenzo_ferrari
Submission time:   2020-04-13 16:48:42
Language:          C++17
Result:            ACCEPTED
*/
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