#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

#define int long long

void query() {
	int k;
	cin >> k;
	if (k <= 9) {
		cout << k << "\n";
		return;
	}

	int p = 1, l = 1; 
	for (; k > 9 * p * l; ++l, p *= 10)
		k -= 9 * p * l;
	--k;
	int num = p + k / l;
	string s = to_string(num);
	cout << s[k % l] << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		query();
	}
}

