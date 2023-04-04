/*
Task:              1072 Two Knights
Sender:            lorenzo_ferrari
Submission time:   2020-06-12 21:47:26
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int64_t solve(int64_t n){
    int64_t tot = n*n;
    switch(n){
        case 1: return 0;
        case 2: return 6;
        case 3: return 28;
        default: return (4LL*(tot-3) + 8LL*(tot-4) + 4LL*(n-3)*(tot-5) + 4LL*(n-4)*(tot-7) + (n-4)*(n-4)*(tot-9))/2LL;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cout << solve(i) << "\n";
}