#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = long long;

#define SQ(a) (a)*(a)

struct pt {
  LL x, y;
  pt() {}
  pt(LL x, LL y) : x(x), y(y) {}
};

pt operator+(const pt& a, const pt& b) { return pt(a.x + b.x, a.y + b.y); }
pt operator-(const pt& a, const pt& b) { return pt(a.x - b.x, a.y - b.y); }
LL operator^(const pt& a, const pt& b) { return a.x*b.y - a.y*b.x; }
ULL operator*(const pt& a, const pt& b) { return a.x*b.x + a.y*b.y; }
istream& operator>>(istream& is, pt& a) { return is >> a.x >> a.y; }

ULL sq_dist(const pt& a, const pt& b) {
  return (a-b)*(a-b);
}

ULL min_dist(vector<pt>& P) {
  // assume P is sorted for x
  int n = P.size();
  ULL ans = 8e18;
  if (n <= 5) {
    for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) {
      ans = min(ans, sq_dist(P[i], P[j]));
    }
    return ans;
  }
  vector<pt> L(P.begin(), P.begin() + n/2);
  vector<pt> R(P.begin() + n/2, P.end());
  ans = min(ans, min_dist(L));
  ans = min(ans, min_dist(R));
  vector<pt> V;
  for (pt p : P) {
    if (SQ(p.x - P[n/2].x) <= ans) {
      V.push_back(p);
    }
  }
  sort(V.begin(), V.end(), [](pt a, pt b){return a.y < b.y;});
  for (int i = 0; i < (int)V.size(); ++i) {
    for (int j = 1; j < 10 && i + j < (int)V.size(); ++j) {
      ans = min(ans, sq_dist(V[i], V[i + j]));
    }
  }
  return ans;
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vector<pt> P(n);
  for (pt& i : P) {
    cin >> i;
  }
  sort(P.begin(), P.end(), [](pt a, pt b){return a.x < b.x;});
  cout << min_dist(P) << "\n";
}

