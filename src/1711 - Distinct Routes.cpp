#include <bits/stdc++.h>
using namespace std;

vector <set<int>> g;
vector <vector<int>> c;
vector <vector<int>> o;

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

void maxflow(int n, int s, int e) {
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

	cout << flow << "\n";

	for (int i = 0; i < flow; i++) {
		int cur = s;
		int len = 1;
		vector <int> tour;
		tour.push_back(s);
		for (;cur != e; len++) {
			for (int nxt : g[cur]) {
				if (c[cur][nxt] < o[cur][nxt]) {
					tour.push_back(nxt);
					c[cur][nxt]++;
					cur = nxt;
					break;
				}
			}
		}

		cout << len << "\n";
		for (int v : tour)
			cout << v+1 << " ";
		cout << "\n";
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	c.assign(n, vector <int> (n));
	o.assign(n, vector <int> (n));

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b; a--, b--;
		g[a].insert(b);
		g[b].insert(a);
		c[a][b]++;
		o[a][b]++;
	}

	maxflow(n, 0, n-1);
}

