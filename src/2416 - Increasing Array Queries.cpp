#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long ll;

const int N = 2e5 + 5;
const int LOG = 18;

ll x[N];
ll p[N];
ll u[N][LOG];
ll w[N][LOG];

ll query(int a, int b) {
    ll ans = -p[b + 1] + p[a];
    while (u[a][0] <= b) {
        int v = 0;
        for (; v < LOG && u[a][v] <= b; ++v);
        --v;
        ans += w[a][v];
        a = u[a][v];
    }
    ans += (b - a + 1) * x[a];

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        p[i + 1] = p[i] + x[i];
    }

    stack<pair<ll, ll>> st;
    st.push({1LL << 60, n});
    for (int i = n - 1; i >= 0; --i) {
        while (st.top().F <= x[i])
            st.pop();
        u[i][0] = st.top().S;
        w[i][0] = (st.top().S - i) * x[i];
        st.push({x[i], i});
    }

    u[n][0] = n;
    w[n][0] = 0;
    for (int i = 1; i < LOG; ++i) {
        for (int j = 0; j <= n; ++j) {
            u[j][i] = u[u[j][i - 1]][i - 1];
            w[j][i] = w[j][i - 1] + w[u[j][i - 1]][i - 1];
        }
    }

    for (int i = 0, a, b; i < q; ++i) {
        cin >> a >> b;
        --a, --b;
        cout << query(a, b) << "\n";
    }
}

