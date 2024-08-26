#include "bits/stdc++.h"
using namespace std;
using LL = long long;

struct Matrix {
    int n;
    vector<vector<double>> a;

    Matrix(int n) : n(n) {
        a.assign(n, vector<double>(n));;
    }

    void make_identity() {
        a.assign(n, vector<double>(n));;
        for (int i = 0; i < n; ++i) {
            a[i][i] = 1;
        }
    };

    Matrix operator*(const Matrix& oth) {
        assert(n == oth.n);
        Matrix ans(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    ans.a[i][j] += a[i][k] * oth.a[k][j];
                }
            }
        }

        return ans;
    };
};

int main() {
    int n; cin >> n;

    static constexpr int N = 8;
    static constexpr array<int, 4> dx{ 0, 1, 0,-1};
    static constexpr array<int, 4> dy{ 1, 0,-1, 0};

    auto idx = [&](int a, int b) -> int {
        return a * N + b;
    };
    auto good = [&](int a, int b) -> bool {
        return 0 <= a && a < N && 0 <= b && b < N;
    };

    Matrix t(N*N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            vector<array<int, 2>> nb;
            for (int k = 0; k < 4; ++k) {
                int ii = i + dx[k];
                int jj = j + dy[k];
                if (good(ii, jj)) {
                    nb.push_back({ii, jj});
                }
            }
            double p = 1.0 / nb.size();
            for (auto [ii, jj] : nb) {
                t.a[idx(i, j)][idx(ii, jj)] = p;
            }
        }
    }

    Matrix cur(N*N);
    cur.make_identity();

    while (n) {
        if (n & 1) {
            cur = t * cur;
        }
        t = t * t;
        n >>= 1;
    }

    double ans = 0;
    for (int i = 0; i < N*N; ++i) {
        double p = 1.0;
        for (int j = 0; j < N*N; ++j) {
            p *= 1 - cur.a[j][i];
        }
        ans += p;
    }

    cout << fixed << setprecision(6) << ans << "\n";
}
