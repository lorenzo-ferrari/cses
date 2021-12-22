#include <iostream>
#include <string>

constexpr int N = 7;
bool vis[N][N];
int cnt = 0, calls = 0;
std::string path;

void solve(int8_t x, int8_t y, int16_t i = 0) {
  ++calls;
  if (i == N*N-1) {
    if (!x && !y) ++cnt;
    return;
  }
  if (!x && !y) return;
  if (y && y != N-1 && !vis[x][y-1] && !vis[x][y+1] && (!x || vis[x-1][y]) && (x == N-1 || vis[x+1][y])) return;
  if (x && x != N-1 && !vis[x-1][y] && !vis[x+1][y] && (!y || vis[x][y-1]) && (y == N-1 || vis[x][y+1])) return;
  vis[x][y] = true;
  if (y && !vis[x][y-1] && (path[i] == 'D' || path[i] == '?')) solve(x, y-1, i+1);
  if (x && !vis[x-1][y] && (path[i] == 'L' || path[i] == '?')) solve(x-1, y, i+1);
  if (y < N-1 && !vis[x][y+1] && (path[i] == 'U' || path[i] == '?')) solve(x, y+1, i+1);
  if (x < N-1 && !vis[x+1][y] && (path[i] == 'R' || path[i] == '?')) solve(x+1, y, i+1);
  vis[x][y] = false;
}

int main() {
  std::cin >> path;
  solve(0, 6);
  std::cout << cnt << "\n";
}

