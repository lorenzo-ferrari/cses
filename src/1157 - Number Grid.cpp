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

