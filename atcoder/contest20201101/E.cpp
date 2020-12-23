#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> H(N);
    for (auto& h : H) {
        cin >> h;
    }
    vector<ll> W(M);
    for (auto& w : W) {
        cin >> w;
    }
    sort(H.begin(), H.end());

    ll ret = 1e10;

    vector<ll> H1((N-1)/2+1);
    vector<ll> H2((N-1)/2+1);
    ll x = 0; 
    ll y = 0;
    for (int k = 0; k <= (N-1) / 2; ++k) {
        x += H[2 * k];
        H1[k] = x;
    }
    for (int k = 0; k <= (N-3) / 2; ++k) {
        y += H[2 * k + 1];
        H2[k] = y;
    }

    for (const auto& w : W) {
        auto it = lower_bound(H.cbegin(), H.cend(), w);
        int m = distance(H.cbegin(), it);
        m /= 2;
        ll sum = 0;
        sum += H2[m-1] - H1[m-1];
        sum += (H1[(N-1)/2] - H1[m]) - (H2[(N-3)/2] - H2[m-1]);

        //for (int k = 0; k < m; ++k) {
        //    sum += H[2*k+1] - H[2*k];
        //}

        //for (int k = m; k <= (N-3)/2; ++k) {
        //    sum += H[2*k+2] - H[2*k+1];
        //}

        sum += abs(H[2*m]-w);
        ret = min(ret, sum);
    }
    cout << ret << endl;
}