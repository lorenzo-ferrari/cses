#include "bits/stdc++.h"
using namespace std;
using LL = long long;

#define SQ(x) (x)*(x)

static constexpr int N = 3003;
static constexpr int K = 3003;
static constexpr LL INF = 1e18;

LL a[N], prf[N], jj[N][K], dp[N][K];

void solve(int l, int r, int k) {
    if (r - l <= 1) return;
    int m = (l + r) / 2;
    dp[m][k] = INF;
    for (int j = jj[l][k]; j <= m && j <= jj[r][k]; ++j) {
        if (dp[m][k] > dp[j][k-1] + SQ(prf[m] - prf[j])) {
            dp[m][k] = dp[j][k-1] + SQ(prf[m] - prf[j]);
            jj[m][k] = j;
        }
    }
    solve(l, m, k);
    solve(m, r, k);
}

int main() {
    int n; cin >> n;
    int k; cin >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prf[i] = prf[i - 1] + a[i];
    }

    for (int i = 1; i <= n; ++i) dp[i][1] = SQ(prf[i]);
    for (int i = 2; i <= k; ++i) {
        jj[0][i] = 1;
        jj[n+1][i] = n;
        solve(0, n+1, i);
    }

    cout << dp[n][k] << "\n";
}
