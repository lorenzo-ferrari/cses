#include "bits/stdc++.h"
using namespace std;
using LL = long long;

static constexpr int N = 20;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<array<int, 3>> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> sos(1 << N);

    auto run = [&]() -> void {
        for (int i = 0; i < N; ++i)
            for (int mask = 0; mask < (1 << N); ++mask)
                if (mask & (1 << i))
                    sos[mask] += sos[mask ^ (1 << i)];
    };
    auto inv = [&](int x) -> int {
        return ~x & ((1 << N) - 1);
    };

    for (int i = 0; i < n; ++i) sos[a[i]] += 1;
    run();
    for (int i = 0; i < n; ++i) ans[i][0] = sos[a[i]];

    sos.assign(1 << N, 0);
    for (int i = 0; i < n; ++i) sos[inv(a[i])] += 1;
    run();
    for (int i = 0; i < n; ++i) ans[i][1] = sos[inv(a[i])];

    sos.assign(1 << N, 0);
    for (int i = 0; i < n; ++i) sos[a[i]] += 1;
    run();
    for (int i = 0; i < n; ++i) ans[i][2] = sos[inv(a[i])];

    for (int i = 0; i < n; ++i) {
        cout << ans[i][0] << " " << ans[i][1] << " " << n - ans[i][2] << "\n";
    }
}
