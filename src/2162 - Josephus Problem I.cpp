/*
Task:              2162 Josephus Problem I
Sender:            lorenzo_ferrari
Submission time:   2021-06-16 14:57:46
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    vector<int> prv(n);
    vector<int> nxt(n);
    for (int i = 0; i < n; i++) {
        prv[i] = (i - 1 + n) % n;
        nxt[i] = (i + 1) % n;
    }

    int cur = 1;
    for (int i = 0; i < n; i++) {
        cout << cur + 1 << " ";
        nxt[prv[cur]] = nxt[cur];
        prv[nxt[cur]] = prv[cur];
        cur = nxt[nxt[cur]];
    }
    cout << "\n";
}
