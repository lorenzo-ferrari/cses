#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n;
    cin >> n;
    int val = 0;
    while(n){
        val += (n/=5);
    }
    cout << val << "\n";
}
