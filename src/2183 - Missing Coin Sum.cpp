/*
Task:              2183 Missing Coin Sum
Sender:            lorenzo_ferrari
Submission time:   2021-06-16 10:44:08
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> c(n);
    for (int& i : c)
        cin >> i;
    sort(c.begin(), c.end());
    long long ans = 1;
    for (int& i : c) {
        if (ans < i) break;
        else ans += i;
    }

    cout << ans << "\n";
}
