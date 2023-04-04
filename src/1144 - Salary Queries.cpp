/*
Task:              1144 Salary Queries
Sender:            lorenzo_ferrari
Submission time:   2021-06-24 19:30:51
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    vector<int> zip(n);

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        zip.push_back(p[i]);
    }

    vector<array<int, 3>> queries(q);
    for (int i = 0, a, b; i < q; ++i) {
        char c;
        cin >> c >> a >> b;
        if (c == '!') {
            zip.push_back(b);
            queries[i] = {1, a, b};
        } else {
            zip.push_back(a);
            zip.push_back(b);
            queries[i] = {0, a, b};
        }
    }

    sort(zip.begin(), zip.end());
    zip.resize(unique(zip.begin(), zip.end()) - zip.begin());

    for (int& i : p) i = lower_bound(zip.begin(), zip.end(), i) - zip.begin();
    for (auto& [c, a, b] : queries) {
        if (!c)
            a = lower_bound(zip.begin(), zip.end(), a) - zip.begin();
        b = lower_bound(zip.begin(), zip.end(), b) - zip.begin();
    }

    const int N = 6e5;

    int t[2 * N] {};

    auto update = [&](int p, int v) {
        for (t[p += N] += v; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    };

    auto query = [&](int l, int r) {
        int ans = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans += t[l++];
            if (r & 1) ans += t[--r];
        }
        return ans;
    };

    for (int i = 0; i < n; ++i)
        ++t[p[i] + N];
    for (int i = N - 1; i >= 0; --i)
        t[i] = t[i << 1] + t[i << 1 | 1];

    for (auto& [c, a, b] : queries) {
        if (c) {
            update(p[a - 1], -1);
            p[a - 1] = b;
            update(p[a - 1], 1);
        } else {
            cout << query(a, b+1) << "\n";
        }
    }
}
