#include <bits/stdc++.h>
using namespace std;
using LL = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct treap {
    LL val = 0, sum = 0;
    int sz = 1, rev = 0, y;
    treap* l = nullptr;
    treap* r = nullptr;

    treap(LL _val) : val(_val), sum(_val), y(rng()) {}
    ~treap() {
        if (l) delete l;
        if (r) delete r;
    }

    friend int get_sz(treap* t) { return t ? t->sz : 0; }
    friend LL get_sum(treap* t) { return t ? t->sum : 0; }
    friend void upd(treap* t) {
        if (!t) return;
        if (t->rev) {
            swap(t->l, t->r);
            reverse(t->l);
            reverse(t->r);
            t->rev = 0;
        }
        t->sum = t->val + get_sum(t->l) + get_sum(t->r);
        t->sz = 1 + get_sz(t->l) + get_sz(t->r);
    }

    friend void reverse(treap* t) {
        if (t) {
            t->rev^= 1;
        }
    }

    friend void split(treap* t, int x, treap*& l, treap*& r) {
        upd(t);
        if (!t) l = r = nullptr;
        if (get_sz(t) <= x) {
            l = t, r = nullptr;
        } else if (get_sz(t->l) >= x) {
            split(t->l, x, l, t->l);
            r = t;
        } else {
            split(t->r, x - 1 - get_sz(t->l), t->r, r);
            l = t;
        }
        upd(l), upd(r);
    }

    friend void merge(treap*& t, treap* l, treap* r) {
        upd(l); upd(r);
        if (!l || !r) t = l ? l : r;
        else if (l->y >= r->y) {
            merge(l->r, l->r, r); t = l;
        } else {
            merge(r->l, l, r->l); t = r;
        }
        upd(t);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int q; cin >> q;
    treap* t = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        merge(t, t, new treap(x));
    }
    for (int i = 0, tt, l, r; i < q; ++i) {
        cin >> tt >> l >> r;
        treap *a, *b, *c;
        split(t, l-1, a, b);
        split(b, r-l+1, b, c);
        if (tt == 1) {
            reverse(b);
        } else {
            cout << get_sum(b) << "\n";
        }
        merge(t, a, b);
        merge(t, t, c);
    }
    delete t;
}
