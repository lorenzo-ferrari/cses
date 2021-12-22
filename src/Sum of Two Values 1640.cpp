#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int& i : v)
        cin >> i;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        if (m.find(k - v[i]) != m.end()) {
            cout << m[k - v[i]] + 1 << " " << i + 1 << "\n";
            return 0;
        }
        m[v[i]] = i;
    }
    cout << "IMPOSSIBLE" << "\n";
}

