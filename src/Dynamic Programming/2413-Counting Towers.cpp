#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int mod = 1e9 + 7;

int main() {
    vector<long long> a(N); a[0] = 1;
    vector<long long> b(N); b[0] = 1;
    for (int i = 1; i < N; ++i) {
        a[i] = (2 * a[i - 1] + b[i - 1]) % mod;
        b[i] = (a[i - 1] + 4 * b[i - 1]) % mod;
    }

    int n; cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        cout << (a[x - 1] + b[x - 1]) % mod << "\n";
    }
}
