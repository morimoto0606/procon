#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

struct S {
    S(mint v, mint w) : _v(v), _w(w) {}
    mint _v;
    mint _w;
};

S op(S a, S b) {
    return S(a._v * b._v + b._v, a._w * b._w);
}

struct F {
    F(int L, int R, mint D) : _L(L), _R(R), _D(D) {}
    int _L;
    int _R;
    mint _D;
};


F composition(F f, F g) {

}

S mapping(F f, S x) {

}

S e() {
    return S(0, 1);
}



int main() {
    lazy_segtree<>
}