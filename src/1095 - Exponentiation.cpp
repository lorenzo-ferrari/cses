/*
Task:              1095 Exponentiation
Sender:            lorenzo_ferrari
Submission time:   2020-11-06 13:22:22
Language:          C++17
Result:            ACCEPTED
*/
#include <iostream>
#pragma GCC optimize ("O3")

const uint64_t mod = 1e9 + 7;

uint64_t fastexp(uint64_t x, uint64_t y) {
    uint64_t ans = 1;
    
    while (y) {
        if (y & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }

    return ans;
}

inline uint64_t get_int() {
    uint64_t n = 0;
    char c = getchar_unlocked();
    while (c >= '0') {
        n = (n << 3) + (n << 1) + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

inline void print(uint64_t n) {
    int64_t i = 0;
    char S[20];
    if (n == 0) {
        putchar_unlocked('0');
        putchar_unlocked('\n');
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

int32_t main() {
    uint64_t t = get_int(), a;

    while (t--) {
        a = get_int();
        print(fastexp(a, get_int()));
    }
}