#include <bits/stdc++.h>
using namespace std;
using LL = long long;

string min_cyc_shift(string s) {
    s += s;
    int n = s.size();
    int i = 0, ans = 0;
    while (i < n/2) {
        ans = i;
        int k = i, j = i+1;
        while (j < n && s[j] >= s[k]) {
            if (s[j] == s[k]) {
                ++k, ++j;
            } else {
                k = i, ++j;
            }
        }
        while (i <= k) i += j - k;
    }
    return s.substr(ans, n/2);
}

int main() {
    string s; cin >> s;
    cout << min_cyc_shift(s) << "\n";
}
