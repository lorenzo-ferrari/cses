#include <bits/stdc++.h>
using namespace std;
using LL = long long;

static constexpr LL mod = 1e9 + 7;

struct Matrix {
    int n;
    vector<vector<LL>> a;
    Matrix(int _n) : n(_n) {
        a.assign(n, vector<LL>(n));
    }
    void make_unit() {
        a.assign(n, vector<LL>(n));
        for (int i = 0; i < n; ++i) {
            a[i][i] = 1;
        }
    }
    friend Matrix mul(const Matrix& a, const Matrix& b) {
        Matrix ans(a.n);
        for (int i = 0; i < a.n; ++i) {
            for (int j = 0; j < a.n; ++j) {
                for (int k = 0; k < a.n; ++k) {
                    ans.a[i][j] += a.a[i][k] * b.a[k][j];
                    ans.a[i][j] %= mod;
                }
            }
        }
        return ans;
    }
    friend Matrix fxp(Matrix x, LL y) {
        Matrix ans(x.n); ans.make_unit();
        while (y) {
            if (y & 1) {
                ans = mul(ans, x);
            }
            x = mul(x, x);
            y >>= 1;
        }
        return ans;
    }
};

int main() {
    LL n; cin >> n;

    Matrix base(2);
    base.a[0][0] = 1;
    base.a[0][1] = 1;
    base.a[1][0] = 1;
    base.a[1][1] = 0;
    auto ans = fxp(base, n);
    cout << ans.a[0][1] << "\n";
}
