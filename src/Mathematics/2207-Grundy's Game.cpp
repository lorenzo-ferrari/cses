#include "bits/stdc++.h"
using namespace std;

int main() {
    // https://oeis.org/A036685
    static constexpr int N = 1222;
    vector<int> g(N+1, -1);
    g[1] = g[2] = 0;
    for (int i = 3; i <= N; ++i) {
        vector<int> mex;
        for (int j = 1; 2*j < i; ++j) {
            mex.push_back(g[j] ^ g[i - j]);
        }
        sort(begin(mex), end(mex));
        mex.erase(unique(begin(mex), end(mex)), end(mex));
        for (int j = 0; j < (int)mex.size(); ++j) {
            if (j != mex[j]) {
                g[i] = j;
                break;
            }
        }
        if (g[i] == -1) {
            g[i] = mex.size();
        }
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n > N || g[n]) {
            cout << "first\n";
        } else {
            cout << "second\n";
        }
    }
}
