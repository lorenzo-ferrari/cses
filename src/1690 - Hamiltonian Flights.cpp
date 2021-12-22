#include <iostream>
#pragma GCC optimize ("Ofast")

inline int get_int() {
    int n = 0;
    char c = getchar_unlocked();
    while ('0' <= c && c <= '9') {
        n = (n<<1) + (n<<3) + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

inline void print(int n) {
    char st[10];
    int i = 0;
    while (n) {
        st[i++] = n % 10 + '0';
        n /= 10;
    }
    while (i--)
        putchar_unlocked(st[i]);
}

int main() {
    const int mod = 1e9 + 7;

    int n = get_int();
    int m = get_int();

    int g[20][20] {};
    for (int a, b; m--;) {
        a = get_int();
        b = get_int();
        ++g[a-1][b-1];
    }

    uint64_t dp[20][1 << 20] {};
    dp[0][1] = 1;
    for (int i = 1, j, k; i < (1 << n); i += 2) {
        if (i & (1 << (n - 1)) && i ^ ((1 << n) - 1)) continue;
        for (j = 0; j < n; ++j) {
            if (!(i & (1 << j))) continue;
            for (k = 0; k < n; ++k)
                if (g[j][k] && ~i & (1 << k))
                    dp[k][i | (1 << k)] = (dp[k][i | (1 << k)] + g[j][k] * dp[j][i]) % mod;
        }
    }

    print(dp[n - 1][(1 << n) - 1]);
}

