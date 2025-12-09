#include "bits/stdc++.h"
using namespace std;
using LL = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	int k; cin >> k;
	array<LL, 26> cnt{};
	array<vector<vector<int>>, 26> pos{};
	for (int c = 0; c < k; ++c) {
		pos[c].resize(n);
	}
	for (int i = 0; i < n; ++i) {
		array<LL, 26> tcnt{};
		for (int j = 0; j < n; ++j) {
			char c; cin >> c;
			++tcnt[c - 'A'];
			pos[c - 'A'][i].push_back(j);
		}
		for (int c = 0; c < k; ++c) {
			cnt[c] += tcnt[c] * (tcnt[c] - 1) / 2;
		}
	}
	vector<bool> mask(n * n);
	for (int c = 0; c < k; ++c) {
		if (cnt[c] > n * (n - 1) / 2) {
			cout << "YES\n";
		} else {
			bool ans = false;
			fill(begin(mask), end(mask), false);
			for (auto& cols : pos[c]) {
				for (int i = 0; i < (int)cols.size() && !ans; ++i) {
					for (int j = i + 1; j < (int)cols.size() && !ans; ++j) {
						if (mask[n * cols[i] + cols[j]]) {
							ans = true;
						}
						mask[n * cols[i] + cols[j]] = true;
					}
				}
			}
			cout << (ans ? "YES\n" : "NO\n");
		}
	}
}
