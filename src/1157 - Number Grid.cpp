/*
Task:              1157 Number Grid
Sender:            lorenzo_ferrari
Submission time:   2022-01-10 14:50:54
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int x, y;
  cin >> x >> y;
  cout << ((x-1)^(y-1)) << "\n";
}
