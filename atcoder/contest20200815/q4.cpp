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

    vector<vector<ll>> dp(K+1, vector<ll>(N));
    for (auto k = 0; k < K; ++k) {
        for (auto i = 0; i < N; ++i) {
            dp[k+1][i] = dp[k][P[i]] + C[P[i]];
        }
    }
    vector<ll> maxVec(K);
    for (auto k = 1; k <= K; ++k) {
        maxVec[k-1] = *max_element(dp[k].cbegin(), dp[k].cend());
    }
    auto max = *max_element(maxVec.cbegin(), maxVec.cend());
    cout << max << endl;
}