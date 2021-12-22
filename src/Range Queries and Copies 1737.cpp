#include <bits/stdc++.h>
using namespace std;
using LL = long long;


struct nd {
    shared_ptr<nd> l;
    shared_ptr<nd> r;
    LL val = 0;
    nd() {}
    nd(shared_ptr<nd> _l, shared_ptr<nd> _r, LL _val) :
        l(_l), r(_r), val(_val) {}
};

void build (shared_ptr<nd> n, int a, int b, vector<LL>& v) {
    if (b - a == 1) {
        n->val = v[a];
        return;
    }
    n->l = make_shared<nd>();
    n->r = make_shared<nd>();
    build(n->l, a, (a + b) / 2, v);
    build(n->r, (a + b) / 2, b, v);
    n->val = n->l->val + n->r->val;
}

void update (shared_ptr<nd> prv, shared_ptr<nd> cur, int a, int b, int idx, int val) {
    if (idx < a || idx >= b)
        return;
    if (b - a == 1) {
        cur->val = val;
        return;
    }

    int m = (a + b) / 2;
    if (idx < m) {
        cur->r = shared_ptr<nd>(prv->r);
        cur->l = make_shared<nd>();
        update(prv->l, cur->l, a, m, idx, val);
    } else {
        cur->l = shared_ptr<nd>(prv->l);
        cur->r = make_shared<nd>();
        update(prv->r, cur->r, m, b, idx, val);
    }
    cur->val = cur->l->val + cur->r->val;
}

LL query (shared_ptr<nd> n, int a, int b, int l, int r) {
    if (!n || r <= a || b <= l)
        return 0;
    if (l <= a && b <= r)
        return n->val;
    return query(n->l, a, (a + b) / 2, l, r) +
           query(n->r, (a + b) / 2, b, l, r);
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    vector<LL> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int nn = 1;
    for (; nn < n; nn <<= 1);
    v.resize(nn);

    vector<shared_ptr<nd>> roots;
    roots.push_back(make_shared<nd>());
    build(roots[0], 0, nn, v);

    for (int t, a, b, k, x; q--;) {
        cin >> t;
        if (t == 1) {
            cin >> k >> a >> x;
            shared_ptr<nd> tmp = make_shared<nd>();
            update(roots[k - 1], tmp, 0, nn, a-1, x);
            roots[k - 1] = tmp;
        } else if (t == 2) {
            cin >> k >> a >> b;
            cout << query(roots[k - 1], 0, nn, a-1, b) << "\n";
        } else if (t == 3) {
            cin >> k;
            roots.push_back(roots[k - 1]);
        }
    }

    roots.clear();
}

