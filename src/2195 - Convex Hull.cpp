#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct pt {
  LL x, y;
  pt() {}
  pt(LL _x, LL _y) : x(_x), y(_y) {}
};
pt operator+(pt a, pt b) { return pt(a.x+b.x, a.y+b.y); }
pt operator-(pt a, pt b) { return pt(a.x-b.x, a.y-b.y); }
LL operator^(pt a, pt b) { return a.x*b.y - b.x*a.y; }
int sign(LL x) { return (x > 0) - (x < 0); }

istream& operator>>(istream& is, pt& a) { return is >> a.x >> a.y; }
ostream& operator<<(ostream& os, const pt a) { return os << a.x << ' ' << a.y; }

vector<pt> upper_half(const vector<pt>& P) {
  // assume P is sorted in increasing order of x
  vector<pt> hull;
  for (int i = 0; i < int(P.size()); ++i) {
    while (hull.size() >= 2) {
      pt A = hull[hull.size() - 2];
      pt B = P[i];
      pt C = hull.back();
      if (sign((A-C)^(B-C)) == 1) {
        hull.pop_back();
      } else {
        break;
      }
    }
    hull.push_back(P[i]);
  }
  return hull;
};

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vector<pt> P(n);
  for (pt& p : P) {
    cin >> p;
  }
  sort(P.begin(), P.end(), [](const pt a, const pt b){
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y; // (?)
  });
  vector<pt> upper; upper.push_back(P[0]);
  vector<pt> lower; lower.push_back(P[0]);
  for (int i = 1; i < n - 1; ++i) {
    LL wedge = (P[0]-P[i])^(P[n-1]-P[i]);
    if (sign(wedge) == -1) upper.push_back(P[i]);
    if (sign(wedge) >=  0) lower.push_back(P[i]);
  }
  upper.push_back(P[n-1]);
  lower.push_back(P[n-1]);

  auto cupper = upper_half(upper);
  for (pt& p : lower) p.y *= -1;
  auto clower = upper_half(lower);
  for (pt& p : clower) p.y *= -1;

  cout << (cupper.size()+clower.size()-2) << "\n";
  for (pt& p : cupper) cout << p << "\n";
  for (int i = clower.size()-2; i > 0; --i) cout << clower[i] << "\n";
}

