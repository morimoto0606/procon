#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    const ll mod = 998244353;
    int N, K;
    cin >> N >> K;
    vector<int> S;
    vector<int> L(K);
    vector<int> R(K);
    for (int i = 0; i < K; ++i) {
        cin >> L[i] >> R[i];
    }
    vector<ll> dp(N);
    vector<ll> sumDp(N+1);
    dp[0] = 1;
    sumDp[1] = dp[0];
    for (int i = 1; i < N; ++i) {
        for (int k = 0; k < K; ++k) {
            dp[i] += (sumDp[max(i-L[k]+1,0)] - sumDp[max(i-R[k],0)]) % mod;
        }
        sumDp[i+1] = (sumDp[i] + dp[i]) % mod;
    }
    cout << dp[N-1] << endl;

}