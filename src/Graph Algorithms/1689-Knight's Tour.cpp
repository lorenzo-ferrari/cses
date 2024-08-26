#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

bool vis[8][8];
int poss[8][8];
vector<pair<int, int>> ans;
vector<pair<int,int>> moves
{   {+1, +2},
    {-1, +2},
    {+1, -2},
    {-1, -2},
    {+2, +1},
    {-2, +1},
    {+2, -1},
    {-2, -1}
};

bool valid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void print() {
    int g[8][8];
    for (int i = 0; i < 64; ++i)
        g[ans[i].S][ans[i].F] = i + 1;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
            cout << g[i][j] << " ";
        cout << "\n";
    }
    exit(0);
}

int cnt;
void solve(int x, int y) {
    vis[x][y] = true;
    ans.push_back({x, y});
    if (ans.size() == 64)
        print();

    vector<array<int, 3>> m;
    for (auto& [dx, dy] : moves)
        if (valid(x + dx, y + dy) && !vis[x + dx][y + dy])
            m.push_back({poss[x + dx][y + dy], x + dx, y + dy});
    sort(m.begin(), m.end());
    for (auto& [p, nx, ny] : m) {
            --poss[nx][ny];
            solve(nx, ny);
            ++poss[nx][ny];
        }

    vis[x][y] = false;
    ans.pop_back();
}

int main() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            for (auto& [di, dj] : moves)
                poss[i][j] += valid(i + di, j + dj);
    int x, y;
    cin >> x >> y;
    --x, --y;

    solve(x, y);
}
