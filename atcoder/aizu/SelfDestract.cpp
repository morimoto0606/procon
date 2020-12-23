#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> L(N);
    vector<ll> R(N);
    for (auto i = 0; i < N; ++i) {
        ll a;
        cin >> a;
        L[i] = a + i;
        R[i] = i - a;
    }
    map<ll, ll> numL;
    for (auto x : L) {
        ++numL[x];
    }
    map<ll, ll> numR;
    for (auto x : R) {
        ++numR[x];
    }
    auto count = 0;
    for (int k = 1; k <= N; ++k) {
        if (numL.count(k) == 0) {
            continue;
        }
        else if (numR.count(k) == 0) {
            continue;
        }
        else {
            count += numL.at(k) * numR.at(k);
        }
    }
    cout << count << endl;
    
}