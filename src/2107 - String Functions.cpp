/*
Task:              2107 String Functions
Sender:            lorenzo_ferrari
Submission time:   2023-03-14 19:43:27
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    string s; cin >> s;
    int n = s.size();
    vector<int> z(n), pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) {
            j = pi[j - 1];
        }
        pi[i] = j + (s[j] == s[i]);
    }
    for (int i = 1, l = 0, r = -1; i < n; ++i) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i, r = i + z[i];
        }
    }

    for (int i = 0; i < n; ++i) cout << z[i]  << " \n"[i == n-1];
    for (int i = 0; i < n; ++i) cout << pi[i] << " \n"[i == n-1];
}
