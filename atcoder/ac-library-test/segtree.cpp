#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

long op(long a, long b) {return max(a, b);}
long e() {return -1;}
long target;
bool f(long a) {return a < target;}
int main() {
    long N, Q;
    cin >> N >> Q;
    vector<long> A(N);
    for (auto &a : A) {
        cin >> a;
    }
    segtree<long, op, e> seg(A);
    for (long i = 0; i < Q; ++i) {
        vector<long> in(3);
        cin >> in[0] >> in[1] >> in[2];
        long ans;
        switch (in[0])
        {
        case 1:
            seg.set(in[1]-1, in[2]);
            break;
        case 2:
        {
            ans = seg.prod(in[1]-1, in[2]);
            cout << ans << endl;
        }
            break;
        case 3:
        {
            target = in[2];
            ans = seg.max_right<f>(in[1]-1)+1;
            cout << ans << endl;
        }
        default:
            break;
        }
    }

}