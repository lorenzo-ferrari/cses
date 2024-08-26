//x-"larghezza", y-"altezza"
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t n;
    cin >> n;
    if((n&3) && ((n+1)&3)){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        int64_t target = n*(n+1)/4;
        vector <int64_t> a, b;
        for(int64_t i = n; i>=1; i--){
            if(i<=target){
                a.push_back(i);
                target-=i;
            }
            else{
                b.push_back(i);
            }
        }

        cout << a.size() << "\n";
        for(int64_t x : a) cout << x << " ";
        cout << "\n" << b.size() << "\n";
        for(int64_t x : b) cout << x << " ";
        cout << "\n";
    }
}