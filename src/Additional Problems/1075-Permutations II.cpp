#include "bits/stdc++.h"
using namespace std;
using LL = long long;

static constexpr LL mod = 1e9 + 7;

int main() {
	int n; cin >> n;
	// dp[i][j] : information about partitioning 1...i in j blocks
	// let X,Y be (possibly empty) blocks, with i's block being in the form X[i]Y
	// dp[i][j][0] : both X and Y are nonempty
	// dp[i][j][1] : exactly one among X and Y is empty
	// dp[i][j][2] : both X and Y are empty
	vector dp(n+1, vector<array<LL, 3>>(n+2));
	dp[1][1][2] = 1;
	for( int i = 2; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j][0] = (dp[i-1][j+1][0]*(j+1)*j + dp[i-1][j+1][1]*j*j + dp[i-1][j+1][2]*j*(j-1)) % mod;
			dp[i][j][1] = (dp[i-1][j][0]*2*j + dp[i-1][j][1]*(2*j-1) + dp[i-1][j][2]*(2*j-2)) % mod;
			dp[i][j][2] = (dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2]) % mod;
		}
	}
	
	LL ans = (dp[n][1][0] + dp[n][1][1] + dp[n][1][2]) % mod;
	cout << ans << "\n";
}
