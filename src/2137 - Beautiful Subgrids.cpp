/*
Task:              2137 Beautiful Subgrids
Sender:            lorenzo_ferrari
Submission time:   2022-10-24 12:58:04
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;

bitset<3000> m[3000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int t = (m[i] & m[j]).count();
            ans += t * (t - 1);
        }
    }
    cout << ans / 2 << "\n";
}
