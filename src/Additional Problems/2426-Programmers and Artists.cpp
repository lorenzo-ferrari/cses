#include "bits/stdc++.h"
using namespace std;
using LL = long long;

static constexpr LL INF = 1e18;

int main() {
    int a; cin >> a;
    int b; cin >> b;
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    set<array<int, 2>> xs, ys;
    for (int i = 0; i < n; ++i) {
        xs.insert({x[i], i});
        ys.insert({y[i], i});
    }

    auto erase = [&](int i) -> void {
        xs.erase({x[i], i});
        ys.erase({y[i], i});
    };

    LL ans = 0;
    int ca = 0, cb = 0;
    priority_queue<int> xtoy;
    priority_queue<int> ytox;
    while (ca != a || cb != b) {
        LL cx_pure = (ca == a ? -INF : (*prev(end(xs)))[0]); // compro x
        LL cy_pure = (cb == b ? -INF : (*prev(end(ys)))[0]); // compro y
        LL cx_swap = (cb == 0 || ca == a ? -INF : (*prev(end(ys)))[0] + ytox.top()); // compro y ma un y' va a x'
        LL cy_swap = (ca == 0 || cb == b ? -INF : (*prev(end(xs)))[0] + xtoy.top()); // compro x ma un x' va a y'

        LL best = max({cx_pure, cy_pure, cx_swap, cy_swap});
        ans += best;
        if (best == cx_pure) {
            ++ca;
            int i = (*prev(end(xs)))[1];
            erase(i);
            xtoy.push(y[i] - x[i]);
        } else if (best == cy_pure) {
            ++cb;
            int i = (*prev(end(ys)))[1];
            erase(i);
            ytox.push(x[i] - y[i]);
        } else if (best == cx_swap) {
            ++ca;
            int i = (*prev(end(ys)))[1];
            erase(i);
            xtoy.push(-ytox.top());
            ytox.pop();
            ytox.push(x[i] - y[i]);
        } else if (best == cy_swap) {
            ++cb;
            int i = (*prev(end(xs)))[1];
            erase(i);
            ytox.push(-xtoy.top());
            xtoy.pop();
            xtoy.push(y[i] - x[i]);
        }
    }
    cout << ans << "\n";
}
