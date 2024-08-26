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
int sign(LL x) { return (int)(x > 0) - (int)(x < 0); }
bool ccw(const pt& A, const pt& B, const pt& C) {
  return ((A-C)^(B-C)) > 0;
}
bool cw(const pt& A, const pt& B, const pt& C) {
  return ((A-C)^(B-C)) < 0;
}

istream& operator>>(istream& is, pt& a) { return is >> a.x >> a.y; }
ostream& operator<<(ostream& os, const pt a) { return os << a.x << ' ' << a.y; }

vector<pt> upper_half(const vector<pt>& P) {
  vector<pt> hull;
  for (int i = 0; i < int(P.size()); ++i) {
    while (hull.size() >= 2) {
      pt A = hull[hull.size() - 2];
      pt B = hull.back();
      pt C = P[i];
      if (ccw(A,B,C)) {
        hull.pop_back();
      } else {
        break;
      }
    }
    hull.push_back(P[i]);
  }
  return hull;
};

vector<pt> lower_half(const vector<pt>& P) {
  vector<pt> hull;
  for (int i = 0; i < int(P.size()); ++i) {
    while (hull.size() >= 2) {
      pt A = hull[hull.size() - 2];
      pt B = hull.back();
      pt C = P[i];
      if (cw(A,B,C)) {
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
    return a.y < b.y;
  });
  vector<pt> upper; upper.push_back(P[0]);
  vector<pt> lower; lower.push_back(P[0]);
  for (int i = 1; i < n - 1; ++i) {
    if (!cw(P[0], P[n-1], P[i])) upper.push_back(P[i]);
    if (!ccw(P[0], P[n-1], P[i])) lower.push_back(P[i]);
  }
  upper.push_back(P[n-1]);
  lower.push_back(P[n-1]);

  auto cupper = upper_half(upper);
  auto clower = lower_half(lower);

  cout << (cupper.size()+clower.size()-2) << "\n";
  for (pt& p : cupper) cout << p << "\n";
  for (int i = clower.size()-2; i > 0; --i) cout << clower[i] << "\n";
}
