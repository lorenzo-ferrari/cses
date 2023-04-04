/*
Task:              2163 Josephus Problem II
Sender:            lorenzo_ferrari
Submission time:   2021-06-26 22:03:49
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

struct st {    
    int n;
    int t[2 * N] {};

    st(int _n) : n(_n) {
        for (int i = 0; i < n; ++i)
            t[i + N] = 1;
        for (int i = N - 1; i > 0; --i)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }

    int lower_bound(int x) {
        int i = 1;
        for (; i < N;) {
            if (t[i << 1] >= x)
                i = i << 1;
            else {
                x -= t[i << 1];
                i = i << 1 | 1;
            }
        }
        return i - N;
    }

    void update(int p, int v) {
        for (t[p += N] = v; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    st t(n);
    for (int i = n, cur = 0; i > 0; --i) {
        cur = ((cur + i) + k) % i;
        int p = t.lower_bound(cur + 1);
        cout << p + 1 << " ";
        t.update(p, 0);
    }
    cout << "\n";
}
