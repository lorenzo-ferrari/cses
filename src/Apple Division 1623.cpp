#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n, ans = 1e18, sum = 0;
    int64_t a[20];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int mask = 0; mask < (1<<n); mask++){
        int64_t t_sum = 0;
        for(int i = 0; i < n; i++)
            if(mask & (1<<i))
                t_sum += a[i];
        ans = min(ans, abs(t_sum-(sum-t_sum)));
    }

    cout << ans << "\n";
}
