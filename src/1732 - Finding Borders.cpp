/*
Task:              1732 Finding Borders
Sender:            lorenzo_ferrari
Submission time:   2021-05-29 18:56:33
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

vector<int> z_algo(string s) {
	int n = s.size();
	vector<int> Z(n);
	Z[0] = -1;
	for (int i = 1, L = 0, R = 0; i < n; i++) {
		if (i > R) {
			L = R = i;
			while (R < n && s[R - L] == s[R])
				R++;
			Z[i] = R - L;
			R--;
		} else {
			if (i + Z[i - L] <= R)
				Z[i] = Z[i - L];
			else {
				L = i;
				while (R < n && s[R - L] == s[R])
					R++;
				Z[i] = R - L;
				R--;
			}
		}
	}
	return Z;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	auto z = z_algo(s);

	int n = s.size();
	for (int i = n-1; i; i--)
		if (z[i] == n - i)
			cout << n-i << " ";
	cout << "\n";
}
