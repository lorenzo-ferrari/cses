#include "bits/stdc++.h"
using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    vector<bool> ans(n+1); ans[0] = false;
    for (int i = 1; i <= n; ++i) {
        for (int x : a) {
            if (x <= i && !ans[i - x]) {
                ans[i] = true;
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << "LW"[ans[i]];
    }
    cout << "\n";
}
