/*
Task:              1706 School Excursion
Sender:            lorenzo_ferrari
Submission time:   2022-02-14 11:29:30
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
 
#define N 100001
#define F(x) for(i=1;i<=x;++i)
 
int p[N], s[N], n, m, a, b, i;
 
int f(int v) {
    return p[v] == v ? v : p[v] = f(p[v]);
}
 
int main() {
    cin >> n >> m;
 
    F(n) p[i] = i, s[i] = 1;
 
    F(m) {
        cin >> a >> b;
        a = f(a);
        b = f(b);
        if (a ^ b) {
            p[b] = a;
            s[a] += s[b];
        }
    }
 
    bitset<N> b; b[0] = 1;
    F(n)
        if (p[i] == i)
            b |= b << s[i];
 
    F(n)
        cout << b[i];
}
