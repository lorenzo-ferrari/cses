#include "bits/stdc++.h"
using namespace std;
using LL = long long;

int main() {
    int n; cin >> n;
    vector<LL> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) a[i] -= b[i];

    auto eval = [](vector<LL> v, LL m) -> LL {
        LL ans = abs(m), prf = 0;
        v[0] += m;
        v.back() -= m;
    
        for (LL i : v) {
            prf += i;
            ans += abs(prf);
        }

        return ans;
    };

    LL l = -1e15, r = 1e15;
    while (r - l > 1) {
        LL m = (l + r) / 2;
        if (eval(a, m) < eval(a, m+1)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << eval(a, r) << "\n";
}
