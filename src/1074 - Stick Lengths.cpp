/*
Task:              1074 Stick Lengths
Sender:            lorenzo_ferrari
Submission time:   2021-06-14 12:04:13
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> v(n);
    for (int& i : v)
        cin >> i;
    nth_element(v.begin(), v.begin() + n/2, v.end());
    
    long long ans = 0;
    for (int i : v)
        ans += abs(v[n/2] - i);
    cout << ans << "\n";
}
