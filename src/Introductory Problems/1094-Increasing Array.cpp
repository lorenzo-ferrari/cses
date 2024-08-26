#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n, ans = 0;
    cin >> n;
    for(int i = 0, mas = 0, a; i < n; i++){
        cin >> a;
        mas = max(a, mas);
        ans += mas-a;
    }
    cout << ans << "\n";
}