//x-"larghezza", y-"altezza"
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        uint64_t x, y;
        cin >> x >> y;
        if(x>=y){
            if(x&1){
                cout << (--x)*x+y << "\n";
            }
            else{
                cout << x*x-y+1 << "\n";
            }
        }
        else{
            if(y&1){
                cout << y*y-x+1 << "\n";
            }
            else{
                cout << (--y)*y+x << "\n";
            }
        }
    }
}
