#include <bits/stdc++.h>
using namespace std;

vector<int> v[100009];
vector<int> color(100010);
bool impossibile = 0;
void dfs(int pos, int col) {
  if (color[pos]) {
    if (color[pos] == col)
      return;
    else {
      impossibile = true;
      return;
    }
  }
  color[pos] = col;
  for (int x : v[pos]) {
    dfs(x, 3 - col);
  }
}
int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 1; i <= N; i++)
    if (!color[i])
      dfs(i, 2);
  if (impossibile)
    cout << "IMPOSSIBLE\n";
  else {
    for (int i = 1; i <= N; i++)
      cout << color[i] << " ";
    cout << endl;
  }
}

