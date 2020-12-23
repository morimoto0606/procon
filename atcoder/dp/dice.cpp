#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    long long D;
    cin >> N >> D;

    ll z = D;
    vector<int> index(3);
    while (z % 2 == 0) {
        z /= 2;
        ++index[0];
    }
    while (z % 3 == 0) {
        z /= 3;
        ++index[1];
    }
    while (z%5 == 0)
    {
        z /=5;
        ++index[2];
    }
    if (z != 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<vector<vector<double>>>> dp(N+1, vector<vector<vector<double>>>(index[0]+1, vector<vector<double>>(index[1]+1, vector<double>(index[2]+1))));
    dp[0][0][0][0] = 1.0;
    const double p = 1./6.;
    for (int n = 0; n < N; ++n) {
        for (int i = 0; i <= index[0]; ++i) {
            for (int j = 0; j <= index[1]; ++j) {
                for (int k = 0; k <= index[2]; ++k) {
                    dp[n+1][i][j][k] += dp[n][i][j][k] * p;
                    dp[n+1][min(i+1,index[0])][j][k] += dp[n][i][j][k] * p;
                    dp[n+1][i][min(j+1,index[1])][k] += dp[n][i][j][k] * p;
                    dp[n+1][min(i+2,index[0])][j][k] += dp[n][i][j][k] * p;
                    dp[n+1][i][j][min(k+1,index[2])] += dp[n][i][j][k] * p;
                    dp[n+1][min(i+1,index[0])][min(j+1,index[1])][k] += dp[n][i][j][k] * p;
                }
            }
        }
    }
    cout << dp[N][index[0]][index[1]][index[2]] << endl;
    return 0;
}