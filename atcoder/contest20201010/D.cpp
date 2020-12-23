#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1000000007;

ll count(ll N, ll A, ll B) {
    ll inner = pow((N-2*(B-1)-A+1) % mod, 2) * pow((A + (B-1))% mod, 2);
    for (int i = 0; i < B-1; ++i) {
        for (int j = 0; j < B-1; ++j) {
            
        }
    }
}

int main() {
    ll T;
    cin >> T;
    for (auto t = 0, t < T; ++t) {
        ll A, B, N;
        cin >> A >> B >> N;
    }
}