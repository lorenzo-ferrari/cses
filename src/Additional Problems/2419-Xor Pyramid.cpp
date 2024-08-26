#include "bits/stdc++.h"
using namespace std;
using LL = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> v2(n);
    for (int i = 2; i < n; ++i) {
        v2[i] = v2[i - 1] + __builtin_ctz(i);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        // n-1 choose i e' dispari?
        if (v2[n-1] == v2[i] + v2[n-1-i]) {
            ans ^= a[i];
        }
    }

    cout << ans << "\n";
}
