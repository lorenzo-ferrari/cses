#include <iostream>
#pragma GCC optimize ("O3")
using namespace std;

inline int64_t get_int() {
    int64_t n = 0;
    char c = getchar_unlocked();
    while (c >= '0') {
        n = (n << 3) + (n << 1) + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

inline void print(int64_t n) {
    int64_t i = 0;
    char S[20];
    if (n == 0) {
        putchar_unlocked('0');
        putchar_unlocked(' ');
        return;
    }
    while (n) {
        S[i++] = n % 10 + '0';
        n /= 10;
    }
    while (--i >= 0)
        putchar_unlocked(S[i]);
    putchar_unlocked('\n');
}

inline int64_t mexp(int64_t x, int64_t y, int64_t mod) {
    int64_t res = 1;
    while (y) {
        if (y & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }

    return res;
}

int32_t main() {
    const int64_t m = 1e9 + 7;
    const int64_t m2 = 1e9 + 6;

    int64_t t = get_int(), a, b, c;
    while (t--) {
        a = get_int();
        b = get_int();
        c = get_int();

        print(mexp(a, mexp(b, c, m2), m));
    }
}
