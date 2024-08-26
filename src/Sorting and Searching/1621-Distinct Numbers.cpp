#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n;
    set <int64_t> S;
    cin >> n;
    for (int i = 0, a; i < n; i++){
        cin >> a;
        S.insert(a);
    }

    cout << S.size() << "\n";
}