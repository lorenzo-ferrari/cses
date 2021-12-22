#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

const int N = 1001;

int m[N][N];
int t[N][N];

void update(int i, int j) {
    m[i][j] ^= 1;
    int v = m[i][j] ? +1 : -1;
    for (int ii = i; ii < N; ii |= ii + 1)
        for (int jj = j; jj < N; jj |= jj + 1)
            t[ii][jj] += v;
}

int query(int i, int j) {
    int ans = 0;
    for (int ii = i; ii >= 0; ii = (ii & (ii + 1)) - 1)
        for (int jj = j; jj >= 0; jj = (jj & (jj + 1)) - 1)
            ans += t[ii][jj];
    return ans;
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char c; cin >> c;
            if (c == '*')
                update(i, j);
        }
    }

    for (int a, y, x, y2, x2; q--;) {
        cin >> a;
        if (a == 1) {
            cin >> y >> x;
            update(y, x);
        } else {
            cin >> y >> x >> y2 >> x2;
            cout << query(y2, x2) + query(y - 1, x - 1) -
                    query(y2, x - 1) - query(y - 1, x2)
                 << "\n";
        }

    }
}

