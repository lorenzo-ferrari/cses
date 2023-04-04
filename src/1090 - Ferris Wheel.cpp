/*
Task:              1090 Ferris Wheel
Sender:            lorenzo_ferrari
Submission time:   2020-10-16 18:46:19
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    for (int &e : a) cin >> e;

    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0, j = n - 1; i <= j; j--, ans++) {
        i += (a[i] + a[j] <= x);
    }

    cout << ans << "\n";
}