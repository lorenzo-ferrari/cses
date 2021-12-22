#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; --n;
    if (!n) {
        cout << 10 << "\n";
        return 0;
    }
    set<int> vis;
    vector<bool> ans;
    function<void(int)> find_euler = [&](int v) {
        int a = (v << 1) & ~(1 << n);
        int b = a | 1;
        if (vis.find(v | (a << n)) == vis.end()) {
            vis.insert(v | (a << n));
            find_euler(a);
        }
        if (vis.find(v | (b << n)) == vis.end()) {
            vis.insert(v | (b << n));
            find_euler(b);
        }
        ans.push_back(v & 1);
    };

    find_euler(0);
    reverse(ans.begin(), ans.end());
    while (--n) cout << 0;
    for (bool i : ans) cout << i;
    cout << "\n";
}

