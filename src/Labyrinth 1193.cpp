#include <iostream>
#pragma GCC optimize ("O3")
#define MAXN (1 << 20) + 42

#define conv(a, b) (a << 10) + b

inline int get_int() {
    int n = 0;
    char c = getchar_unlocked();
    while (c >= '0') {
        n = (n << 3) + (n << 1) + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

inline void print(int n) {
    int i = 0;
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
    while (i--)
        putchar_unlocked(S[i]);
    putchar_unlocked('\n');
}

int main() {
    int n = get_int();
    int m = get_int();
    int Q[MAXN]{};
    bool mp[MAXN]{};
    char tramite[MAXN]{};
    int txa = 0, txb = 0, r = 0, l = 0, tx;
    char c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c = getchar_unlocked();
            if (c == 'A') {txa = conv(i, j);}
            if (c == 'B') {txb = conv(i, j);}
            mp[conv(i, j)] = (c != '#');
        }
        c = getchar_unlocked();
    }
    
    Q[l++] = txa;
    tramite[txa] = 'A';
    while (l != r) {
        tx = Q[r++];
        if ((tx >> 10) > 0 && mp[tx - (1 << 10)] && !tramite[tx - (1 << 10)]) {
            tramite[tx - (1 << 10)] = 'U';
            Q[l++] = tx - (1 << 10);
        }
        if ((tx >> 10) < n - 1 && mp[tx + (1 << 10)] && !tramite[tx + (1 << 10)]) {
            tramite[tx + (1 << 10)] = 'D';
            Q[l++] = tx + (1 << 10);
        }
        if (tx - ((tx >> 10) << 10) > 0 && mp[tx - 1] && !tramite[tx - 1]) {
            tramite[tx - 1] = 'L';
            Q[l++] = tx - 1;
        }
        if (tx - ((tx >> 10) << 10) < m - 1 && mp[tx + 1] && !tramite[tx + 1]) {
            tramite[tx + 1] = 'R';
            Q[l++] = tx + 1;
        }
    }

    if (!tramite[txb]) {
        putchar_unlocked('N');
        putchar_unlocked('O');
        return 0;
    }

    putchar_unlocked('Y');
    putchar_unlocked('E');
    putchar_unlocked('S');
    putchar_unlocked('\n');
    
    int ans = 0;
    char S[MAXN];
    while (txb != txa) {
        S[ans++] = tramite[txb];
        if (tramite[txb] == 'U') {txb += (1 << 10);}
        else if (tramite[txb] == 'D') {txb -= (1 << 10);}
        else if (tramite[txb] == 'L') {txb++;}
        else if (tramite[txb] == 'R') {txb--;}
    }
    print(ans);
    while (ans--) putchar_unlocked(S[ans]);
}
