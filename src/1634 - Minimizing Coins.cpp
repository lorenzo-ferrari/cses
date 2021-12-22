#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n, target;
    int64_t v[100], dp[1000005];

    cin >> n >> target;
    fill(dp+1, dp+target+2, 1000000007);
    dp[0] = 0;

    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v, v+n);

    for(int i = 1; i <= target; i++){
        for(int m = 0; m < n; m++){
            if(v[m] > i) break;
            dp[i] = min(dp[i], 1+dp[i-v[m]]);
        }
    }

    if(dp[target] == 1000000007)
        cout << -1 << "\n";
    else 
        cout << dp[target] << "\n";
}
