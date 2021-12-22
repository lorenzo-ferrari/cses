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
	return (sgn(e) != sgn(f) && sgn(g) != sgn(h));
}

bool boundary(int n, vector<pt> &P, pt &A) {
	for (pt Q : P)
		if (A == Q)
			return true;
	for (int i = 0; i < n; i++)
		if (isOnSegment(A, P[i], P[(i+1)%n]))
			return true;
	return false;
}

void locate(int n, vector<pt> &P, pt &A) {
	if (boundary(n, P, A)) { cout << "BOUNDARY\n"; return; }
	pt Q = pt(1, 2e9);
	int k = 0;
	for (int i = 0; i < n; i++)
		k += intersect(A, Q, P[i], P[(i+1)%n]);
	cout << (k & 1 ? "INSIDE" : "OUTSIDE") << "\n";
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pt> P(n);
	for (int i = 0; i < n; i++)
		cin >> P[i];
	for (int i = 0; i < m; i++) {
		pt A;
		cin >> A;
		locate(n, P, A);
	}
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}

