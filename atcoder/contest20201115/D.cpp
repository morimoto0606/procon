#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    ll N, W;
    cin >> N >> W;
    vector<ll> S(N);
    vector<ll> T(N);
    vector<ll> P(N);
    vector<ll> v;
    for (int i = 0; i < N; ++i) {
        cin >> S[i] >> T[i] >> P[i];
        v.push_back(S[i]);
        v.push_back(T[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<ll> water(v.size());
    for (int i = 0; i < N; ++i) {
        auto itS = find(v.begin(), v.end(), S[i]);
        auto itT = find(itS, v.end(), T[i]);
        int start = distance(v.begin(), itS);
        int end = distance(v.begin(), itT);
        for (int j = start; j < end; ++j) {
            water[j] += P[i];
            if (water[j] > W) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

}