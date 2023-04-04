/*
Task:              1696 School Dance
Sender:            lorenzo_ferrari
Submission time:   2020-12-26 20:24:54
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

vector <set<int>> g;
vector <vector<int>> c;

const int INF = 1e9;
int bfs(int s, int e, vector <int> &par) {
	fill(par.begin(), par.end(), -1);
	queue <pair<int, int>> Q;
	Q.push({s, INF});

	while (!Q.empty()) {
		int v = Q.front().first;
		int flow = Q.front().second;
		Q.pop();

		for (int u : g[v]) {
			if (par[u] == -1 && c[v][u]) {
				par[u] = v;
				int new_flow = min(flow, c[v][u]);
				if (u == e)
					return new_flow;
				Q.push({u, new_flow});
			}
		}
	}

	return 0;
}

void maxflow(int n, int tn, int tm, int s, int e) {
	int flow = 0;
	int new_flow;
	vector <int> par(n);

	while (new_flow = bfs(s, e, par)) {
		assert(new_flow == 1);
		flow += new_flow;
		int cur = e;
		while (cur != s) {
			int prv = par[cur];
			c[cur][prv] += new_flow;
			c[prv][cur] -= new_flow;
			cur = prv;
		}
	}

	cout << flow << "\n";

	for (int i = 1; i <= tn; i++)
		for (int j = tn+1; j <= tn+tm; j++)
			if (g[i].find(j) != g[i].end() && c[i][j] == 0)
				cout << i << " " << j-tn << "\n";
}

int main() {
	int n, m, k, tot;
	cin >> n >> m >> k;
	tot = n + m + 2;
	g.resize(tot);
	c.assign(tot, vector <int> (tot));

	for (int i = 0, a, b; i < k; i++) {
		cin >> a >> b;
		b += n;
		g[a].insert(b);
		g[b].insert(a);
		c[a][b] = 1;
		// c[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		g[0].insert(i);
		// g[i].insert(0);
		c[0][i] = 1;
		// c[i][0] = 1;
	}
	for (int i = n+1; i <= n + m; i++) {
		// g[tot-1].insert(i);
		g[i].insert(tot-1);
		// c[tot-1][i] = 1;
		c[i][tot-1] = 1;
	}

	maxflow(tot, n, m, 0, tot-1);
}
