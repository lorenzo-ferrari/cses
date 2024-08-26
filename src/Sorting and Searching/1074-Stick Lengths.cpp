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
