#include "bits/stdc++.h"
using namespace std;
using LL = long long;

int main() {
    int n; cin >> n;
    int k; cin >> k;

    double bin[101][101]{};
    for (int i = 1; i <= 100; ++i) {
        bin[i][0] = bin[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            bin[i][j] = bin[i-1][j-1] + bin[i-1][j];
        }
    }

    double ans = 0;
    ans += pow(1.0 / k, n);
    for (int m = 2; m <= k; ++m) {
        double p = 0;
        for (int cnt = 1; cnt <= n; ++cnt) {
            p += bin[n][cnt] * pow(1.0 / k, cnt) * pow(1.0 * (m-1) / k, n-cnt);
        }
        ans += m * p;
    }

    cout << fixed << setprecision(6) << ans;
}
