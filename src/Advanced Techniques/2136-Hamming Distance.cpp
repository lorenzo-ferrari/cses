#pragma GCC optimize ("O3")
#pragma GCC target ("popcnt")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int k; cin >> k;
    bitset<30> v[20000];
    size_t ans = 30;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        for (int j = 0; j < i; ++j) {
            ans = min(ans, (v[i]^v[j]).count());
        }
    }
    cout << ans << "\n";
}
