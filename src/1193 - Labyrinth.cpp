/*
Task:              1193 Labyrinth
Sender:            lorenzo_ferrari
Submission time:   2022-12-21 18:04:51
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
// 5 8
// ########
// #.A#...#
// #.##.#B#
// #......#
// ########

int dx[4]{1, 0, -1, 0};
int dy[4]{0, 1, 0, -1};
char dir[4]{'D', 'R', 'U', 'L'};

int main() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  array<int, 2> a, b;
  vector<vector<bool>> good(n, vector<bool>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      if (c != '#') {
        good[i][j] = true;
      }
      if (c == 'A') {
        a = {i, j};
      } else if (c == 'B') {
        b = {i, j};
      }
    }
  }

  vector<vector<int>> d(n, vector<int>(m, 1e9));
  vector<vector<char>> from(n, vector<char>(m, ' '));
  queue<array<int, 2>> Q;
  Q.push(a);
  d[a[0]][a[1]] = 0;
  while (!Q.empty()) {
    auto [x, y] = Q.front();
    Q.pop();

    for (int i = 0; i < 4; ++i) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];
      if (new_x < 0 || new_x >= n)
        continue;
      if (new_y < 0 || new_y >= m)
        continue;
      if (!good[new_x][new_y])
        continue;
      if (d[new_x][new_y] > d[x][y] + 1) {
        d[new_x][new_y] = d[x][y] + 1;
        Q.push({new_x, new_y});
        from[new_x][new_y] = dir[i];
      }
    }
  }

  if (d[b[0]][b[1]] == 1e9) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    cout << d[b[0]][b[1]] << "\n";

    auto cur = b;
    string ans = "";
    while (cur != a) {
      // cerr << cur[0] << " " << cur[1] << endl;
      array<int, 2> nxt;
      for (int i = 0; i < 4; ++i) {
        if (from[cur[0]][cur[1]] == dir[i]) {
          nxt[0] = cur[0] - dx[i];
          nxt[1] = cur[1] - dy[i];
          ans.push_back(dir[i]);
          break;
        }
      }
      cur = nxt;
    }
    reverse(begin(ans), end(ans));
    cout << ans << "\n";
  }
}
