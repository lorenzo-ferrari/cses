#include <bits/stdc++.h>
using namespace std;

vector<int> c, ans;
vector<vector<int>> adj;

set<int> dfs(int v, int par) {
	set<int> s;
	for (int u : adj[v]) {
		if (u == par) {
			continue;
		}
		auto tmp = dfs(u, v);
		if (tmp.size() > s.size()) { // importantissimo
			swap(tmp, s);	// O(1)
		}
		for (int x : tmp) {
			s.insert(x);
		}
	}
	s.insert(c[v]);
	ans[v] = s.size();

	return s;	// O(1)
}

int main() {
	int n; cin >> n;
	c.resize(n);
	adj.resize(n);
	ans.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	for (int i = 0, a, b; i < n - 1; ++i) {
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, -1);

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " \n"[i == n-1];
	}
}
