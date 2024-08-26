#include "bits/stdc++.h"
using namespace std;
using LL = long long;

static constexpr int N = 3003;
static constexpr int K = 3003;
static constexpr LL INF = 1e18;


struct item {
    LL val;
    int jj;
};

int n;
item dp[K][N];
LL a[N], prf[N], sum[N], c[N][N];

static void precalc() {
    for (int l = 1; l <= n; ++l) {
        for (int r = l+1; r <= n; ++r) {
            LL tot = prf[r] - prf[l - 1];

            // binsearch sul primo m t.c. 2 * (prf[m] - prf[l - 1] >= tot)
            int ll = l-1, rr = r;
            while (rr - ll > 1) {
                int m = (ll + rr) / 2;
                if (2 * (prf[m] - prf[l - 1]) >= tot) {
                    rr = m;
                } else {
                    ll = m;
                }
            }

            int p = rr; // school at position p
            c[l][r] += (prf[p] - prf[l-1]) * p - (sum[p] - sum[l-1]);
            c[l][r] += (sum[r] - sum[p]) - (prf[r] - prf[p]) * p;
        }
    }
}

static void solve(int l, int r, int k) {
    if (r - l <= 1) return;
    int m = (l + r) / 2;
    dp[k][m].val = INF;
    for (int j = dp[k][l].jj; j <= m && j <= dp[k][r].jj; ++j) {
        if (dp[k][m].val > dp[k-1][j-1].val + c[j][m]) {
            dp[k][m].val = dp[k-1][j-1].val + c[j][m];
            dp[k][m].jj = j;
        }
    }
    solve(l, m, k);
    solve(m, r, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int k; cin >> k;
    ::n = n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prf[i] = prf[i - 1] + a[i];
        sum[i] = sum[i - 1] + a[i] * i;
    }

    precalc();

    for (int i = 1; i <= n; ++i) dp[1][i].val = c[1][i];
    for (int i = 2; i <= k; ++i) {
        dp[i][0].jj = 1;
        dp[i][n+1].jj = n;
        solve(0, n+1, i);
    }

    cout << dp[k][n].val << "\n";
}
