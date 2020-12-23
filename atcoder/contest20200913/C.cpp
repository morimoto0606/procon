#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll modPow(ll a, ll n, ll mod) {
    ll res  = 1;
    for (ll i = 0; i < n; ++i) {
        res *= a;
        res %= mod;
    }
    return res;
}

int main() 
{
    const ll mod = 1e9 + 7;
    ll N;
    cin >> N;
    ll x1 = modPow(10, N, mod);
    ll x2 = 2 * modPow(9, N, mod);
    ll x3 = modPow(8, N, mod);
    ll res = (x1 - x2 + x3 + 2 * mod) % mod;
    cout << res << endl;
}