/*
Task:              2193 Polygon Lattice Points
Sender:            lorenzo_ferrari
Submission time:   2021-05-23 22:03:41
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

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

LL area2(int N, vector<pt> P) {
	LL ans = 0;
	for (int i = 0; i < N; i++)
		ans += (P[i] ^ P[(i+1)%N]);
	return ans > 0 ? ans : -ans;
}

void solve() {
	int N;
	cin >> N;
	vector<pt> P(N);
	for (pt &x : P)
		cin >> x;
	LL A2 = area2(N, P);
	LL B = 0;
	for (int i = 0; i < N; i++)
		B += __gcd(abs((P[i]-P[(i+1)%N]).x), abs((P[i]-P[(i+1)%N]).y));
	LL ans = (A2 - B) / 2 + 1;
	cout << ans << " " << B << "\n";
}

// Pick's theorem: A = a + b/2 - 1
// 2A = 2a + b - 2
// 2a = 2A - b + 2

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	while (t--)
		solve();
}
