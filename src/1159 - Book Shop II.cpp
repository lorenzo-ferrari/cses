/*
Task:              1159 Book Shop II
Sender:            lorenzo_ferrari
Submission time:   2021-12-04 10:50:43
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct book {
  int pr;
  int pg;
  book(int a, int b) : pr(a), pg(b) {}
};

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int x; cin >> x;
  vector<int> oh(n), os(n), ok(n);
  for (int i = 0; i < n; ++i) cin >> oh[i];
  for (int i = 0; i < n; ++i) cin >> os[i];
  for (int i = 0; i < n; ++i) cin >> ok[i];
  vector<book> books;
  for (int i = 0, h, s, k; i < n; ++i) {
    h = oh[i], s = os[i], k = ok[i];
    for (int j = 1; j < k; j <<= 1) {
      books.push_back(book(h*j, s*j));
      k -= j;
    }
    books.push_back(book(h*k, s*k));
  }
  // for (auto& [a, b] : books)
  //   cout << a << " " << b << "\n";
  vector<int> dp(x+1);
  for (book& b : books) {
    for (int j = x; j > 0; --j) {
      if (j >= b.pr)
        dp[j] = max(dp[j], dp[j - b.pr] + b.pg);
    }
    for (int j = 0; j < x; ++j)
      dp[j + 1] = max(dp[j], dp[j + 1]);
  }
  cout << dp[x] << "\n";
}
