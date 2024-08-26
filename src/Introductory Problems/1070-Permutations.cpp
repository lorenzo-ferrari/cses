#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if(n == 2 || n == 3){
        cout << "NO SOLUTION\n";
        return 0;
    }
    vector <int> s(n);
    if(!(n&1)){
        for(int i = 1; i <= n; i++){
            if(i&1){
                s[(n>>1)+(i>>1)] = i;
            }
            else{
                s[(i>>1)-1] = i;
            }
            
        }
    }
    else{
        s[n>>1] = n;
        for(int i = 1; i <= n-1; i++){
            if(i&1){
                s[n-1-(i>>1)] = i;
            }
            else{
                s[(n>>1)-(i>>1)] = i;
            }
            
        }
    }

    for(int x : s)
        cout << x << " ";
    cout << "\n";    
}