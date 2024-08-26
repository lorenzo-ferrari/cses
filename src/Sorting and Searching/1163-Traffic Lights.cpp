#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, n;
    cin >> x >> n;

    set<pair<int, int>> m;
    multiset<int> s;
    m.insert({0, x});
    s.insert(x);
    for (int i = 0, l, r, p; i < n; i++) {
        cin >> p;
        auto it = m.upper_bound({p, -1}); --it;
        l = it->first;
        r = it->second;
        m.erase(it);
        s.erase(s.find(r - l));
        m.insert({l, p});
        m.insert({p, r});
        s.insert({p - l});
        s.insert({r - p});

        cout << *s.rbegin() << " ";
    }
    cout << "\n";
}
