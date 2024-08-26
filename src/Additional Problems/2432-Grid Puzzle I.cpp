#include "bits/stdc++.h"
using namespace std;

static constexpr int INF = 1e9;

int dfs(int n, int s, int e, vector<vector<int>> &g, vector<vector<int>> &c, vector<int> &par) {
	par.assign(n, -1);
	stack<pair<int, int>> st;
	st.push({s, INF});
	while (!st.empty()) {
		int v = st.top().first;
		int flow = st.top().second;
        st.pop();

		for (int u : g[v])
			if (par[u] == -1 && c[v][u]) {
				int new_flow = min(flow, c[v][u]);
				par[u] = v;
				if (u == e)
					return new_flow;
				st.push({u, new_flow});
			}
	}

	return 0;
}

int maxflow(int n, int s, int e, vector<vector<int>> &g, vector<vector<int>> &c) {
	int flow = 0;
	int new_flow;
	vector<int> par;
	while (new_flow = dfs(n, s, e, g, c, par)) {
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

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    int sa = accumulate(begin(a), end(a), 0);
    int sb = accumulate(begin(b), end(b), 0);

    int nn = 2 * n + 2;
    vector<vector<int>> adj(nn);
    vector<vector<int>> c(nn, vector<int>(nn));

    auto add_edge = [&](int a, int b, int cap = 1) -> void {
        adj[a].push_back(b);
        adj[b].push_back(a);
        c[a][b] += cap;
    };

    int src = 0;
    int snk = nn - 1;
    for (int i = 0; i < n; ++i) {
        add_edge(src, i+1, a[i]);
        add_edge(i+n+1, snk, b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            add_edge(i, j+n);
        }
    }

    int m = maxflow(nn, src, snk, adj, c);
    if (m != sa || m != sb) {
        cout << "-1\n";
    } else {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << "X."[c[i][j+n]];
            }
            cout << "\n";
        }
    }
}
