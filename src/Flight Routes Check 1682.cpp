#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int p[N];

int find_set(int v) {
	return v == p[v] ? v : p[v] = find_set(p[v]);
}

void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	p[b] = a;
}

vector <int> g[N];
vector <int> gr[N];
bool vis[N];

void dfs1(int v) {
	vis[v] = true;
	for (int u : g[v])
		if (!vis[u])
			dfs1(u);
}

void dfs2(int v) {
	vis[v] = true;
	for (int u : gr[v])
		if (!vis[u])
			dfs2(u);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		gr[b].push_back(a);
	}

	dfs1(0);

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			cout << "NO" << "\n";
			cout << 1 << " " << i+1 << "\n";
			return 0;
		}
	}

	fill(vis, vis + n, false);

	dfs2(0);

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			cout << "NO" << "\n";
			cout << i+1 << " " << 1 << "\n";
			return 0;
		}
	}

	cout << "YES" << "\n";
}

