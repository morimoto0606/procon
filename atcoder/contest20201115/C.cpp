#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> T(N, vector<ll>(N));
    for (auto& t : T) {
        for (auto& x : t) {
            cin >> x;
        }
    }
    vector<ll> timeVec;
    vector<ll> v(N-1);
    iota(v.begin(), v.end(), 1); 
    do {
        ll time = 0;
        time += T[0][v[0]];
        for (auto i = 0; i < N -2; ++i) {
            time += T[v[i]][v[i+1]];
        }
        time += T[v[N-2]][0];
        timeVec.push_back(time);
    } while( next_permutation(v.begin(), v.end()) );  
    auto ret = count(timeVec.begin(), timeVec.end(), K);
    cout << ret << endl;
}