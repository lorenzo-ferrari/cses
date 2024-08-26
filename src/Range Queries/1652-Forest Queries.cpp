#include <bits/stdc++.h>
using namespace std;

int pref[1001][1001];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q;
    scanf("%d %d", &n, &q);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {

            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            char c;
            cin >> c;
            if(c == '*') pref[i][j]++;           
        }
    }

    for(int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        //cin >> x1 >> x2 >> y1 >> y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        //printf("%d %d %d %d\n", x1, y1, x2, y2);
        x1--; y1--;
        int res = (pref[x2][y2] + pref[x1][y1] - pref[x1][y2] - pref[x2][y1]);
        printf("%d\n", res);
    } 
}