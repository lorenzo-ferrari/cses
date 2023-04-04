/*
Task:              1621 Distinct Numbers
Sender:            lorenzo_ferrari
Submission time:   2020-05-09 13:44:02
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n;
    set <int64_t> S;
    cin >> n;
    for (int i = 0, a; i < n; i++){
        cin >> a;
        S.insert(a);
    }

    cout << S.size() << "\n";
}