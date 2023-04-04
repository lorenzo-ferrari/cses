/*
Task:              2205 Gray Code
Sender:            lorenzo_ferrari
Submission time:   2021-06-11 23:42:59
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int32_t main() {
    int n;
    cin >> n;

    vector<string> v(1 << n);
    v[0] = "0";
    v[1] = "1";
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < (1 << i); j++)
            v[j + (1 << i)] = v[j];
        reverse(v.begin() + (1 << i), v.begin() + (1 << (i + 1)));
        for (int j = 0; j < (1 << i); ++j) {
            v[j] = "0" + v[j];
            v[j + (1 << i)] = "1" + v[j + (1 << i)];
        }
    }

    for (auto &s : v)
        cout << s << "\n";
}
