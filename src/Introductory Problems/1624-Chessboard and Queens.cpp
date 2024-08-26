#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int ans;
bool m[8][8];
vector <pair<int, int>> placed;

bool isPOssible(pair<int, int> c){
    int x = c.first, y = c.second;
    for(auto q : placed){
        int tx = q.first, ty = q.second;
        if(x == tx || y == ty || abs(tx-x) == abs(ty-y)) return false;
    }

    return !m[x][y];
}

void solve(int step){
    if(step == 8){
        ++ans;
    }
    else{
        for(int i = 0; i < 8; i++){
            if(isPOssible({step, i})){
                placed.push_back({step, i});
                solve(step+1);
                placed.pop_back();
            }
        }
    }    
}

int main(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            char c; cin >> c;
            m[i][j] = (c == '*');
        }
    }
    /*for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << m[i][j];
        }
        cout << "\n";
    }*/
    solve(0);
    cout << ans << "\n";
}