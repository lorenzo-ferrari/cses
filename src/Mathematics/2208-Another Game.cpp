#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n; cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt += (x & 1);
    }
    cout << (cnt ? "first" : "second") << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
