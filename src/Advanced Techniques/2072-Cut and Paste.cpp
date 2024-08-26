#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct treap {
    char c;
    int cnt, y;
    treap* l = nullptr;
    treap* r = nullptr;

    treap(){}
    treap(char _c) : c(_c), cnt(1), y(rng()) {}
    ~treap() {
        if (l) delete l;
        if (r) delete r;
    }

    friend int sz(treap* t) { return t ? t->cnt : 0; }
    friend void upd(treap* t) {
        if (t) {
            t->cnt = 1 + sz(t->l) + sz(t->r);
        }
    }

    friend void split(treap* t, int x, treap*& l, treap*& r) {
        upd(t);
        if (!t) l = r = nullptr;
        if (sz(t) <= x) {
            l = t, r = nullptr;
        } else if (sz(t->l) >= x) {
            split(t->l, x, l, t->l);
            r = t;
        } else {
            split(t->r, x - 1 - sz(t->l), t->r, r);
            l = t;
        }
        upd(l), upd(r);
    }

    friend void merge(treap*& t, treap* l, treap* r) {
        if (!l || !r) t = l ? l : r;
        else if (l->y >= r->y) {
            merge(l->r, l->r, r), t = l;
        } else {
            merge(r->l, l, r->l), t = r;
        }
        upd(t);
    }

    friend void print(treap* t) {
        if (!t) return;
        print(t->l);
        cout << t->c;
        print(t->r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int q; cin >> q;
    treap* t = nullptr;
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        merge(t, t, new treap(c));
    }
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r;
        // [a][b][c] to [a][c][b]
        treap *a, *b, *c;
        split(t, l-1, a, b);
        split(b, r-l+1, b, c);
        merge(t, a, c);
        merge(t, t, b);
    }
    print(t);
    delete t;
}
