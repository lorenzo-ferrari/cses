#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

#define F first
#define S second
typedef long long LL;

struct pt {
	LL x, y;
	pt(): x(0), y(0) {}
	pt(LL x, LL y): x(x), y(y) {}
	double norm() { return sqrt(x*x + y*y); }
//	bool is_on_line(pt A, pt B)
};
istream& operator >>(istream &in, pt &A) { return in >> A.x >> A.y; }
ostream& operator <<(ostream &out, const pt &A) { return out << '(' << A.x << ',' << A.y << ')'; }

pt operator +(const pt &A, const pt &B) { return pt(A.x + B.x, A.y + B.y); }
pt operator -(const pt &A, const pt &B) { return pt(A.x - B.x, A.y - B.y); }
LL operator ^(pt A, pt B) { return A.x*B.y - A.y*B.x; }
bool operator ==(pt A, pt B) { return A.x == B.x && A.y == B.y; }

int sgn(LL x) {
	if (x == 0) return x;
	if (x > 0) return 1;
	return -1;
}

int quad(pt A) {
	if (A.x >= 0 && A.y >= 0) return 1;
	if (A.x <  0 && A.y >= 0) return 2;
	if (A.x <  0 && A.y <  0) return 3;
	if (A.x >= 0 && A.y <  0) return 4;
	return 69;
}

bool align(pt C, pt A, pt B) { return ((A-C)^(B-C)) == 0; }
bool isOnSegment(pt C, pt A, pt B) { return align(C, A, B) && quad(A-C) != quad(B-C); }

bool intersect(pt A, pt B, pt C, pt D) {
	LL e, f, g, h;
	e = (A-C)^(B-C); f = (A-D)^(B-D);
	g = (C-A)^(D-A); h = (C-B)^(D-B);
	return (sgn(e) != sgn(f) && sgn(g) != sgn(h)) ||
		isOnSegment(C, A, B) ||
		isOnSegment(D, A, B) ||
		isOnSegment(A, C, D) ||
		isOnSegment(B, C, D);
}

void solve() {
	pt A, B, C, D;
	cin >> A >> B >> C >> D;

	cout << (intersect(A, B, C, D) ? "YES" : "NO") << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}

