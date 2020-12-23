#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for (ll& x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end(), greater<ll>());
    vector<vector<double>> dp(N, vector<double>(K+1));
    for (ll k = 0; k <= K; ++k) {
        dp[0][k] = (double)a[0] / (k + 1);
    }
    for (ll n = 0; n < N-1; ++n) {
        for (ll k = 0; k <= K; ++k) {
            for (ll l = 0; l <= k; ++l) {
                if (dp[n][k-l] > (double)a[n+1]/(l+1)) {
                    if (l==0) {
                        dp[n+1][k] = dp[n][k];
                    }
                    else {
                        dp[n+1][k] = min(dp[n][k-l], (double)a[n+1] / l);
                    }
                    break;
                }
            }
        }
    }
    cout << (ll)ceil(dp[N-1][K]) << endl;



    return 0;
}