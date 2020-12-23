#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    ll N;
    cin >> N;
    vector<pair<ll, ll>> P(N);
    for (auto& p : P)  {
        cin >> p.first >> p.second;
    }
    vector<vector<ll>> dp(N, vector<ll>(N));
    for (auto i = 0; i < N; ++i) {
        dp[i][0] = abs(P[i].first - P[0].first) + abs(P[i].second - P[0].second);
    }
    for (auto i = 0; i < N; ++i) {
        for (auto j = 1; j < N; ++j) {
            ll d = abs(P[i].first - P[j].first) + abs(P[i].second - P[j].second);
            dp[i][j] = max(dp[i][j-1], d);
        }
    }
    ll res = 0;
    for (const auto& x : dp) {
        res = max(res, x.back());
    }
    cout << res << endl;

}