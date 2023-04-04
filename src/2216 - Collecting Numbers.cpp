/*
Task:              2216 Collecting Numbers
Sender:            lorenzo_ferrari
Submission time:   2021-06-16 10:49:43
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

    vector<pair<int, int>> v(n);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v[i] = {x, i};
    }

    sort(v.begin(), v.end());

    int ans = 1;
    for (int i = 1; i < n; i++)
        ans += (v[i - 1].second > v[i].second);

    cout << ans << "\n";
}
