#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

#define S second

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> o(n);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> o[i];
        v[i] = {o[i], i};
    }
    v.push_back({-1, -1});
    v.push_back({n + 1, n + 1});

    sort(v.begin(), v.end());

    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans += (v[i - 1].S > v[i].S);

    function<void()> query = [&]() {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (o[a] > o[b]) swap(a, b);
        int A = o[a], B = o[b];
        if (B - A == 1) {
            ans -= (v[A - 1].S > v[A].S);
            ans -= (v[A].S > v[B].S);
            ans -= (v[B].S > v[B + 1].S);
            v[A].S = b; v[B].S = a;
            swap(o[a], o[b]);
            ans += (v[A - 1].S > v[A].S);
            ans += (v[A].S > v[B].S);
            ans += (v[B].S > v[B + 1].S);
        } else {
            ans -= (v[A - 1].S > v[A].S);
            ans -= (v[A].S > v[A + 1].S);
            ans -= (v[B - 1].S > v[B].S);
            ans -= (v[B].S > v[B + 1].S);
            v[A].S = b; v[B].S = a;
            swap(o[a], o[b]);
            ans += (v[A - 1].S > v[A].S);
            ans += (v[A].S > v[A + 1].S);
            ans += (v[B - 1].S > v[B].S);
            ans += (v[B].S > v[B + 1].S);
        }
        cout << ans << "\n";
    };

    for (int i = 0; i < m; i++)
        query();
}

