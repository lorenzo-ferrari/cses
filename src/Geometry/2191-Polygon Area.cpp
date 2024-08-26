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

void solve() {
	int n;
	cin >> n;
	vector<pt> P(n);
	for (int i = 0; i < n; i++)
		cin >> P[i];
	LL ans = 0;
	for (int i = 1; i < n; i++)
		ans += ((P[i]-P[0])^(P[(i+1)%n]-P[0]));
	cout << (ans > 0 ? ans : -ans) << "\n";
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
