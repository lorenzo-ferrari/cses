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

void solve() {
	pt A, B, C;
	cin >> A >> B >> C;

	LL vec = (A-C)^(B-C);

	if (vec == 0) cout << "TOUCH\n";
	if (vec < 0) cout << "RIGHT\n";
	if (vec > 0) cout << "LEFT\n";
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
