/*
Task:              1192 Counting Rooms
Sender:            lorenzo_ferrari
Submission time:   2020-05-22 13:20:16
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
bool mat[1000][1000], vis[1000][1000];

void dfs(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m || !mat[x][y] || vis[x][y])
        return;
    vis[x][y] = 1;

    dfs(x+1, y);
    dfs(x, y+1);
    dfs(x-1, y);
    dfs(x, y-1);
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            mat[i][j] = (c=='.');
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] && !vis[i][j]){
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans << "\n";
}