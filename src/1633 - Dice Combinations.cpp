/*
Task:              1633 Dice Combinations
Sender:            lorenzo_ferrari
Submission time:   2020-05-09 12:59:36
Language:          C++17
Result:            ACCEPTED
*/
//x-"larghezza", y-"altezza"
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t n;
    int64_t dp[1000002];
    dp[0] = 1;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int64_t tot = 0;
        for(int j = i-1; j >= i-6 && j >= 0; j--)
            tot += dp[j];
        dp[i] = tot%MOD;
    }

    cout << dp[n] << "\n";
}