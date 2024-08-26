#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> k(n);
    for (int& i : k)
        cin >> i;
    
    int ans = 0;
    set<int> st;
    for (int r = 0, l = 0; r < n; r++) {
        while (st.find(k[r]) != st.end())
            st.erase(k[l++]);
        st.insert(k[r]);
        ans = max(ans, r - l + 1);
    }

    cout << ans << "\n";
}
