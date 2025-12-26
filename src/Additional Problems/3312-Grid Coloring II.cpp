// https://cses.fi/problemset/task/3312
// can be reduced to 2-SAT!
// x_{i, j} = 0 if cell (i, j) contains g[i][j] + 1 
// x_{i, j} = 1 if cell (i, j) contains g[i][j] + 2 
// diverity constraints between adjacent cells
#include "bits/stdc++.h"
using namespace std;
using clause_t = array<array<int, 2>, 2>;

clause_t make_clause(int x, bool negx, int y, bool negy) {
	return clause_t{array<int, 2>{x, (int)negx}, array<int, 2>{y, negy}};
}

optional<vector<bool>> solve_2sat(int n, vector<clause_t> clauses) {
	vector<vector<int>> adj(2 * n);
	vector<vector<int>> rdj(2 * n);
	auto add_edge = [&](int i, int j) -> void {
		adj[i].push_back(j);
		rdj[j].push_back(i);
	};
	for (auto [l1, l2] : clauses) {
		add_edge(2 * l1[0] + (l1[1] ^ 1), 2 * l2[0] + l2[1]);
		add_edge(2 * l2[0] + (l2[1] ^ 1), 2 * l1[0] + l1[1]);
	}

	vector<int> o;
	{
		vector<bool> vis(2 * n);
		auto dfs = [&](auto&& self, int v) -> void {
			vis[v] = true;
			for (int u : adj[v])
				if (!vis[u])
					self(self, u);
			o.push_back(v);
		};
		for (int i = 0; i < 2 * n; ++i)
			if (!vis[i])
				dfs(dfs, i);
		reverse(begin(o), end(o));
	}

	vector<int> vis(2 * n);
	{
		int round = 0;
		auto dfs = [&](auto&& self, int v) -> void {
			vis[v] = round;
			for (int u : rdj[v])
				if (!vis[u])
					self(self, u);
		};
		for (int v : o) {
			if (!vis[v]) {
				++round;
				dfs(dfs, v);
			}
		}
	}

	vector<bool> ans(n);
	for (int i = 0; i < n; ++i) {
		if (vis[2 * i] == vis[2 * i + 1])
			return nullopt;
		else
			ans[i] = (vis[2 * i] < vis[2 * i + 1]);
	}

	return ans;
}

int main() {
	int n; cin >> n;
	int m; cin >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c; cin >> c;
			g[i][j] = c - 'A';
		}
	}

	vector<clause_t> clauses;
	auto map = [&](int i, int j) -> int {
		return i * m + j;
	};
	auto add_contraints = [&](int i1, int j1, int i2, int j2) -> void {
		for (int d1 = 0; d1 <= 1; ++d1)
			for (int d2 = 0; d2 <= 1; ++d2)
				if ((g[i1][j1] + d1 - g[i2][j2] - d2) % 3 == 0)
					clauses.push_back(make_clause(map(i1, j1), d1 ^ 1, map(i2, j2), d2 ^ 1));
	};

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i != 0) add_contraints(i - 1, j, i, j);
			if (j != 0) add_contraints(i, j - 1, i, j);
		}
	}

	auto result = solve_2sat(n * m, clauses);
	if (result.has_value()) {
		auto assignment = result.value();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << char('A' + (g[i][j] + 1 + assignment[map(i, j)]) % 3);
			}
			cout << "\n";
		}
	} else {
		cout << "IMPOSSIBLE\n";
	}
}
