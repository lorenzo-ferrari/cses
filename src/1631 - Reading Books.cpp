/*
Task:              1631 Reading Books
Sender:            lorenzo_ferrari
Submission time:   2021-06-21 15:22:53
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long s = 0;
    vector<int> t(n);
    for (int& i : t) {
        cin >> i;
        s += i;
    }

    for (int& i : t) {
        if (2 * i >= s) {
            cout << 2 * i << "\n";
            return 0;
        }
    }

    cout << s << "\n";
}
