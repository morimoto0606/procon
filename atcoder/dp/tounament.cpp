#include <bits/stdc++.h>
using namespace std;

double prob(double rp, double rq) {
    return 1./(1. + pow(10., (rq - rp)/400.));
}

int main() {
    int K;
    cin >> K;
    int num = pow(2, K);
    vector<double> R(num);
    for (double& r : R) {
        cin >> r;
    }
    vector<vector<double>> dp(K+1, vector<double>(num));
    dp[0] = vector<double>(num, 1.0);
    for (int k = 1; k <=K; ++k) {
        for (int m = 0; m < num; ++ m) {
            bitset<10> bm(m);
            bm.flip(k-1);
            double p = 0;
            for (int b = 0; b < pow(2, k-1); ++b) {
                bitset<10> bb(b);
                for (int i = 0; i < k-1; ++i) {
                    bm.set(i, bb.test(i));
                }
                int idx = bm.to_ulong();
                p += prob(R[m], R[idx]) * dp[k-1][idx];
            }
            dp[k][m] = dp[k-1][m] * p;
        }
    }
    for (int i = 0; i < num; ++i) {
        cout << dp[K][i] << endl;
    }
    return 0;
}