/*
Task:              1083 Missing Number
Sender:            lorenzo_ferrari
Submission time:   2020-04-30 12:31:14
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n, sum;
    cin >> n;
    sum = (n*(n+1))>>1;
    for(int i = 1, t; i < n; i++){
        cin >> t;
        sum -= t;
    }
    cout << sum << "\n";
}