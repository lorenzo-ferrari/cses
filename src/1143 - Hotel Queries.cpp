#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

int n, m;
int t[2 * N];

void update(int p, int v) {
    for (t[p += N] = v; p > 1; p >>= 1)
        t[p >> 1] = max(t[p], t[p ^ 1]);
}

int l_bound(int x) {
    if (t[1] < x) return -1;
    int i = 1;
    for (; i < N;)
        i = (t[i << 1] >= x) ? i << 1 : i << 1 | 1;
    return i - N;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> t[i + N];
    for (int i = N - 1; i > 0; --i)
        t[i] = max(t[i << 1], t[i << 1 | 1]);

    for (int i = 0, r; i < m; ++i) {
        cin >> r;
        int j = l_bound(r);
        if (j == -1) {
            cout << 0 << " ";
            continue;
        } else {
            cout << j + 1 << " ";
            update(j, t[j + N] - r);
        }
    }
}

