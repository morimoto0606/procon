#include  <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll M = 998244353;
ll convert(const vector<ll>& v, const string& s) {
    ll res = 0;
    for (ll i = 0; i < s.length(); ++i) {
        res += (s[i]-'0') * v[s.length()-1-i] % M;
        res %= M;
    }
    if (res < 0) {
        res += M;
    }
    return res;
}

int main() {
    ll N, Q;
    cin >> N >> Q;
    string S(N, '1');

    vector<ll> v(N);
    v[0] = 1;
    for (int i = 1; i < N; ++i) {
        v[i] = 10 * v[i-1] % M;
    }
    for (auto i = 0; i < Q; ++i) {
        ll L, R;
        cin >> L >> R;
        char D;
        cin >> D;
        string newPart(R-L+1, D);
        string last = S.substr(R, N-R);
        S = S.substr(0, L-1)+newPart+ S.substr(R, N-R);
        ll res = convert(v, S);
        cout << res << endl;
    }
}
