/*
Task:              1145 Increasing Subsequence
Sender:            lorenzo_ferrari
Submission time:   2021-09-07 14:10:24
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

struct ft {
    int n;
    vector<int> t;
    ft(int _n) : n(_n) {
        t.assign(n, 0);
    }
    void upd(int p, int v) {
        for (; p < n; p |= p + 1)
            t[p] = max(t[p], v);
    }
    int query(int r) {
        int ans = 0;
        for (; r > 0; r = (r & (r + 1)) - 1)
            ans = max(ans, t[r]);
        return ans;
    }
};

vector<int> compr(vector<int>& a) {
    int n = a.size();
    vector<int> ans(n);
    vector<int> x = a;
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    for (int i = 0; i < n; ++i)
        ans[i] = lower_bound(x.begin(), x.end(), a[i]) - x.begin() + 1;
    return ans;
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int& i : a)
        cin >> i;
    auto x = compr(a);
    ft t(n + 1);
    for (int i = 0; i < n; ++i)
        t.upd(x[i], t.query(x[i] - 1) + 1);
    cout << t.query(n) << "\n";
}
