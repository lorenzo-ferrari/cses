/*
Task:              1635 Coin Combinations I
Sender:            lorenzo_ferrari
Submission time:   2020-05-09 13:38:07
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n, target;
    int64_t v[100], dp[1000005] { };
    dp[0] = 1;
    cin >> n >> target;
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v, v+n);

    for(int i = 1; i <= target; i++){
        for(int m = 0; m < n; m++){
            if(v[m] > i) break;
            dp[i] += dp[i-v[m]];
        }
        dp[i] %= MOD;
    }

    cout << dp[target] << "\n";
}