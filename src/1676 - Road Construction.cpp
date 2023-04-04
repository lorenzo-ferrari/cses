/*
Task:              1676 Road Construction
Sender:            lorenzo_ferrari
Submission time:   2021-06-19 19:40:15
Language:          C++17
Result:            ACCEPTED
*/
#include <iostream>

#define C std::cin >>

int n, m, x, a, b, i, p[1<<17], s[1<<17];

int f(int v) {
    return p[v] ^ v ? p[v] = f(p[v]) : v;
}

int main() {
    C n >> m;

    for (; i <= n; ++i) p[i] = i, s[i] = 1;
    for (; C a >> b ;) {
        a = f(a);
        b = f(b);
        if (a ^ b) {
            p[b] = a;
            s[a] += s[b];
            x = x > s[a] ? x : s[a];
            --n;
        }
        printf("%d %d\n", n, x);
    }
}
