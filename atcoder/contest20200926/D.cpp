#include  <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    vector<vector<ll>> D(N);
    D[0] = {A[0]};
    for (auto n = 0; n < N-1; ++n) {
        for (auto l = n; l > 0; --l) {
            for (const auto& x: D[l-1]) {
                if (abs(x - A[n+1]) <= K) {
                    D[l].push_back(A[n+1]);
                    break;
                }
            }
        }
        D[0].push_back(A[n+1]);
    }
    ll maxL = 0;
    for (int l = 0; l < N; ++l) {
        if (!D[l].empty()) {
            maxL = l;
        }
    }
    cout << maxL + 1<< endl;

}