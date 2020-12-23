#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> P(N);
    vector<ll> C(N);
    for (auto& p : P) {
        cin >> p;
        --p;
    }
    for (auto& c : C) {
        cin >> c;
    }

    vector<ll> a(N);
    ll res = *max_element(C.cbegin(), C.cend());
    for (auto k = 0; k < K; ++k) {
        vector<ll> b;
        transform(P.cbegin(), P.cend(), back_inserter(b), [&a, &C](ll p){return a[p] + C[p];});
        a = b;
    }
    res = max(res, *max_element(a.cbegin(), a.cend()));
    cout << res << endl;
}