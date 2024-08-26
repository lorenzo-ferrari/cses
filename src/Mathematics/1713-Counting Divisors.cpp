#include <bits/stdc++.h>
using namespace std;

int d(int n) {
    int ans = 0;
    for (int i = 1; i * i <= n; ++i) {
        ans += 2 * (n % i == 0);
        ans -= (i * i == n);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    for (int x; n--;) {
        cin >> x;
        cout << d(x) << "\n";
    }
}
