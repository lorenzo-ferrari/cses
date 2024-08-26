#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0, j = 0; i < n && j < m; i++) {
        while (j < m && b[j] <= a[i] && a[i]-b[j] > k) j++;
        if (j < m && abs(a[i]-b[j]) <= k) {
            //cout << j << "\n";
            ans++; j++;
        }
    };

    cout << ans << "\n";
}