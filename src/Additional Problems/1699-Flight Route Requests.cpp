// https://cses.fi/problemset/task/1699
// solution:
// connect each SCC containing >1 node with a cycle, the condensation graph boils
// it down to the DAG case. Each CC in the dag must be connected, therefore at
// least #CC-1 edges are needed; they are also sufficient by building the edges
// (v_i, v_{i+1}) where v_i is the i-th node in a toposort.
// ans = n - #{CC : not exists S subset CC, S SCC with #S > 1}
//	   = n - #{CC with a cycle}

#include "bits/stdc++.h"
using namespace std;
using LL = long long;

int main() {
	int n; cin >> n;
	int m; cin >> m;
	vector<vector<int>> adj(n);
	vector<vector<int>> rdj(n);
	for (int i = 0, a, b; i < m; ++i) {
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		rdj[b].push_back(a);
	}

	int cnt = 0;
	vector<int> cc(n);
	auto find_cc = [&](auto&& self, int v) -> void {
		cc[v] = cnt;
		for (int u : adj[v]) {
			if (!cc[u]) {
				self(self, u);
			}
		}
		for (int u : rdj[v]) {
			if (!cc[u]) {
				self(self, u);
			}
		}
	};

	// find the CC of the undirected graph
	for (int i = 0; i < n; ++i) {
		if (!cc[i]) {
			++cnt;
			find_cc(find_cc, i);
		}
	}

	// find the SCC
	vector<bool> cycle(cnt + 1);
	{
		vector<int> o;
		vector<bool> vis(n);
		auto dfs = [&](auto&& self, int v) -> void {
			vis[v] = true;
			for (int u : adj[v]) {
				if (!vis[u]) {
					self(self, u);
				}
			}
			o.push_back(v);
		};
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				dfs(dfs, i);
			}
		}
		reverse(begin(o), end(o));
		vector<int> scc;
		auto dfs2 = [&](auto&& self, int v) -> void {
			scc.push_back(v);
			vis[v] = true;
			for (int u : rdj[v]) {
				if (!vis[u]) {
					self(self, u);
				}
			}
		};
		vis.assign(n, false);
		for (int v : o) {
			if (!vis[v]) {
				scc.clear();
				dfs2(dfs2, v);
				if ((int)scc.size() >= 2) {
					cycle[cc[scc[0]]] = true;
				}
			}
		}
	}

	int ans = n - cnt + count(begin(cycle), end(cycle), true);
	cout << ans << "\n";
}
