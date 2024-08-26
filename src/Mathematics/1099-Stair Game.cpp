#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n; cin >> n;
    int xr = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (i & 1) {
            xr ^= x;
        }
    }
    cout << (xr ? "first" : "second") << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
