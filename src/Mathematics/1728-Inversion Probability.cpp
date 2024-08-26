#include "bits/stdc++.h"
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    vector<int> num(10001);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            // don't overthink if it's not necessary :P
            int cnt = 0;
            for (int x = 1; x <= r[i]; ++x) {
                for (int y = 1; y <= r[j] && y < x; ++y) {
                    ++cnt;
                }
            }
            int a = cnt;
            int b = r[i] * r[j];
            int g = __gcd(a, b);
            num[b / g] += a / g;
        }
    }
    long double ans = 0;
    for (int i = 1; i <= 100*100; ++i) {
        ans += (long double)num[i] / i;
    }
 
    printf("%.6lf\n", (double)ans);
}
