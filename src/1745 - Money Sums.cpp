/*
Task:              1745 Money Sums
Sender:            lorenzo_ferrari
Submission time:   2021-08-27 15:04:50
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int n;
    cin >> n;

    bitset<100001> b; b[0] = 1;
    for (int i = 0, a; i < n; ++i) {
        cin >> a;
        b |= b << a;
    }

    vector<int> ans;
    for (int i = 1; i <= 1e5; ++i)
        if (b[i])
            ans.push_back(i);
    
    cout << ans.size() << "\n";
    for (int& i : ans)
        cout << i << " ";
    cout << "\n";
}
