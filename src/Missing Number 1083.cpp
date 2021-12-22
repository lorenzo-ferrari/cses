#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n, sum;
    cin >> n;
    sum = (n*(n+1))>>1;
    for(int i = 1, t; i < n; i++){
        cin >> t;
        sum -= t;
    }
    cout << sum << "\n";
}
