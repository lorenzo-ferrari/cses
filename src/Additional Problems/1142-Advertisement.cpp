#include <stack>
#include <vector>
#include <iostream>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector <int> h(n), nxt(n), prv(n);
    for (int &i : h) cin >> i;
    stack <pair<int, int>> st;
    st.push({-1, n});
    for (int i = n - 1; i >= 0; i--) {
        while (st.top().first > h[i])
            st.pop();
        nxt[i] = st.top().second;
        st.push({h[i], i});
    }

    while (!st.empty())
        st.pop();
    st.push({-1, -1});
    for (int i = 0; i < n; i++) {
        while (st.top().first >= h[i])
            st.pop();
        prv[i] = st.top().second;
        st.push({h[i], i});
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, h[i] * (nxt[i] - prv[i] - 1));
    }

    cout << ans << "\n";
}