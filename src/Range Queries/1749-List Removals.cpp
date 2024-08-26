#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

int t[2 * N];

int query(int p) {
    int i = 1;
    for (;i < N;) {
        if (t[i << 1] >= p)
            i = i << 1;
        else {
            p -= t[i << 1];
            i = i << 1 | 1;
        }
    }

    return i - N;
}

void update(int p, int v) {
    for (t[p += N] = v; p > 1; p >>= 1)
        t[p >> 1] = t[p] + t[p ^ 1];
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t[i + N] = 1;
    }
    for (int i = N - 1; i > 0; --i)
        t[i] = t[i << 1] + t[i << 1 | 1];

    for (int i = 0, p; i < n; ++i) {
        cin >> p;
        int j = query(p);
        cout << a[j] << " ";
        update(j, 0);
    }
}
