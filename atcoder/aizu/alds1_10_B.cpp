#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;
    vector<pair<long, long>> size(n);
    for (auto& v : size) {
        cin >> v.first >> v.second;
    }
    vector<vector<long long>> dp(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            vector<long long> v;
            for (int k = i; k < j; ++k) {
                double d = dp[i][k] + dp[k+1][j] + size[i].first * size[j].second * size[k].second;
                v.push_back(d);
            }
            auto d = *min_element(v.begin(), v.end());
            dp[i][j]  = d;
        }
    }
    cout << dp[0][n-1] << endl;

}