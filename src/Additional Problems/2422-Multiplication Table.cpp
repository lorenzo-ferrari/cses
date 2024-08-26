#include "bits/stdc++.h"
using namespace std;
using LL = long long;

int main() {
    LL n; cin >> n;

    LL pos = n * n / 2 + 1;
    auto count = [&](LL x) -> LL {
        // ritorna quante entrate sono <= x
        LL ans = 0;
        for (LL a = 1, b = n; a <= n; ++a) {
            while (a * b > x) {
                --b;
            }
            ans += b;
        }
        return ans;
    };

    LL l = 0, r = n * n;
    while (r - l > 1) {
        LL m = (l + r) / 2;
        if (count(m) < pos) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << r << "\n";
}
