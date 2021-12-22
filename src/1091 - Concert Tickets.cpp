#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    multiset<int> s;
    for (int h; n--;) {
        cin >> h;
        s.insert(h);
    }

    for (int t; m--;) {
        cin >> t;
        if (s.empty() || *s.begin() > t)
            cout << -1 << "\n";
        else {
            auto it = s.upper_bound(t);
            --it;
            cout << *it << "\n";
            s.erase(it);
        }
    }
}

