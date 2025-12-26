// https://cses.fi/problemset/task/3359
#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; cin >> n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<char>> g(n, vector<char>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> g[i][j];
	vector<vector<int>> dp(n, vector<int>(n));
	vector<array<int, 4>> v;
	vector<vector<array<int, 4>>> buckets;
	for (int sum = 1; sum <= 2 * n - 2; ++sum) {
		v.clear();
		v.reserve(n);
		for (int i = max(0, sum - n + 1); i < n && i <= sum; ++i) {
			int j = sum - i;
			int prv = n;
			if (i != 0)
				prv = min(prv, dp[i - 1][j]);
			if (j != 0)
				prv = min(prv, dp[i][j - 1]);
			v.push_back({prv, g[i][j], i, j});
		}
		for (int c = 1; c >= 0; --c) {
			buckets.assign(max(n, 128), {});
			for (auto& x : v) {
				buckets[x[c]].push_back(x);
			}
			int cnt = 0;
			for (auto& b : buckets) {
				for (auto x : b) {
					v[cnt++] = x;
				}
			}
		}
		for (int i = 0, cnt = 0; i < (int)v.size(); ++i) {
			cnt += (i && (v[i - 1][0] != v[i][0] || v[i - 1][1] != v[i][1]));
			dp[v[i][2]][v[i][3]] = cnt;
		}
	}

	string ans;
	int i = n - 1, j = n - 1;
	while (true) {
		ans.push_back(g[i][j]);
		if (i == 0 && j == 0)
			break;
		else if (i == 0) --j;
		else if (j == 0) --i;
		else if (dp[i - 1][j] < dp[i][j - 1]) {
			--i;
		} else {
			--j;
		}
	}

	reverse(begin(ans), end(ans));

	cout << ans << "\n";
}
