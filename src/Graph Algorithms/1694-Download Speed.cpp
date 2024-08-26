#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
 
vector <set<int>> g;
vector <vector<int>> c;
 
const int INF = 1e15;
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
 
int maxflow(int n, int s, int e) {
	int flow = 0;
	int new_flow;
	vector <int> par(n);
 
	while (new_flow = bfs(s, e, par)) {
		flow += new_flow;
		int cur = e;
		while (cur != s) {
			int prv = par[cur];
			c[prv][cur] -= new_flow;
			c[cur][prv] += new_flow;
			cur = prv;
		}
	}
 
	return flow;
}
 
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
 
	g.resize(n);
	c.assign(n, vector <int> (n));
 
	for (int i = 0, a, b, cp; i < m; i++) {
		cin >> a >> b >> cp; a--, b--;
		g[a].insert(b);
		g[b].insert(a);
		c[a][b] += cp;
	}
 
	cout << maxflow(n, 0, n-1) << "\n";
}
