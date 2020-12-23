#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x, ll m) {
    return x * x % m;
}
int main() 
{
    ll N, X, M;
    cin >> N >> X >> M;
    map<ll, ll> A;
    ll a = X;
    A.emplace(a, 1);
    ll sum = 0;
    ll m0, n0;
    vector<ll> sumVec;
    for (auto i = 2; i <= M+1; ++i) {
        sum += a;
        sumVec.push_back(sum);
        a = f(a, M);
        if (A.count(a) == 1) {
            m0 = i;
            n0 = A.at(a);
            break;
        }
        else {
            A.emplace(a, i);
        }
    }
    ll res = 0;
    if (n0 > N) {
        cout << sumVec[N-1] << endl;
        return 0;
    }
    ll sum1 = sumVec[n0-1]; //accumulate(sumVec.begin(), sumVec.begin() + n0-1, 0);
    ll sum2 = accumulate(sumVec.begin() + n0, sumVec.begin() + m0-1, 0);
    ll q = N - (n0-1) % (m0-n0);
    ll p = (N - (n0-1)-q) / (m0-n0);
    ll sum3 = accumulate(sumVec.begin() + n0, sumVec.begin() + n0+q-1, 0);
    res = sum1 + p * sum2 + sum3;
    cout << res << endl;
}