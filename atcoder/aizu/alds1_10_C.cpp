#include <bits/stdc++.h>
using namespace std;

int lcs(const string& X,
    const string& Y) 
{
    int lenX = X.length();
    int lenY = Y.length();
    vector<vector<int>> dp(lenX + 1, vector<int>(lenY + 1));
    for (int i = 1; i <= lenX; ++i) {
        for (int j = 1; j <= lenY; ++j) {
            if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[lenX][lenY];
}

int main() {
    int q;
    cin >> q;
    vector<string> Xs(q);
    vector<string> Ys(q);
    for (int i = 0; i < q; ++i) {
        cin >> Xs[i];
        cin >> Ys[i];
    }
    for (int i = 0; i < q; ++i) {
        cout << lcs(Xs[i], Ys[i]) << endl;
    }



}