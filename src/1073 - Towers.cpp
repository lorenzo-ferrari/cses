/*
Task:              1073 Towers
Sender:            lorenzo_ferrari
Submission time:   2021-06-16 13:44:55
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int32_t main() {
    int n;
    cin >> n;

    multiset<int> st;
    for (int i = 0, k; i < n; i++) {
        cin >> k;
        multiset<int>::iterator it = st.upper_bound(k);
        if (it != st.end())
            st.erase(it);
        st.insert(k);
    }

    cout << st.size() << "\n";
}
