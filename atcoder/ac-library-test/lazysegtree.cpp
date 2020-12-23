#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using S = modint998244353;
S op(S a, S b) {return a + b;}
S e(){return 0;}
struct F {
    F(S b, S c) : _b(b), _c(c) {}
    S _b;
    S _c;
};
S mapping(F f, S x) {
    return f._b * x + f._c;
}
F comparison(F f, F g) {
    return F{f._b * g._b, f._b * g._c + f._c};
}
F id() {
    return F{1, 0};
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<S> A(N);
    for (auto& a : A) {
        int x = 0;
        cin >> x;
        a = x;
    }
    lazy_segtree<S, op, e, F, mapping, comparison, id> seg(A);
    for (int q = 0; q < Q; ++q) {
        bool x;
        cin >> x;
        if (x==0) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            F f{b, c};
            seg.apply(l, r, f);
        }
        else {
            int l, r;
            cin >> l >> r;
            S ans = seg.prod(l, r);
            cout << ans.val() << endl;
        }
    }
}