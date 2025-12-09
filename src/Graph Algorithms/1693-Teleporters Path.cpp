#include "bits/stdc++.h"
using namespace std;
using LL = long long;

int main() {
	int n; cin >> n;
	int m; cin >> m;
	vector<int> deg(n + 1);
	vector<multiset<int>> adj(n + 1);
	for (int i = 0, a, b; i < m; ++i) {
		cin >> a >> b;
		adj[a].insert(b);
		++deg[a];
		--deg[b];
	}
	--deg[1];
	++deg[n];
	adj[n].insert(1);
	if (*max_element(begin(deg), end(deg)) != 0) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	vector<int> tour;
	auto dfs = [&](auto &&self, int v) -> void {
		while (!adj[v].empty()) {
			int u = *begin(adj[v]);
			adj[v].erase(begin(adj[v]));
			self(self, u);
		}
		tour.push_back(v);
	};

	dfs(dfs, 1);
	tour.pop_back();
	reverse(begin(tour), end(tour));
	if ((int)tour.size() != m + 1) {
		cout << "IMPOSSIBLE\n";
	} else {
		int i = 0;
		while (tour[i] != n || tour[(i + 1) % (m + 1)] != 1)
			++i;
		rotate(begin(tour), begin(tour) + i + 1, end(tour));
		for (int x : tour)
			cout << x << " ";
		cout << "\n";
	}
}
