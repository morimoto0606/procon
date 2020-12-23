#include <bits/stdc++.h>
using namespace std;

int main() {
    int aSize;
    cin >> aSize;
    vector<int> A(aSize);
    for (auto&& a : A) {
        cin >> a;
    }

    int qSize;
    cin >> qSize;
    vector<int> Q(qSize);
    for (auto&& q : Q) {
        cin >> q;
    }

    int maxQ = *max_element(Q.cbegin(), Q.cend());
    vector<vector<bool>> dp(aSize, vector<bool>(2001, false));
    for (int j = 1; j <= maxQ; ++j) {
        if (A[0] == j) {
            dp[0][j] = true;
        }
    }

    for (int i = 0; i < aSize-1; ++i) {
        dp[i][0] = true;
        for (int j = 1; j <= maxQ; ++j) {
            if (dp[i][j]) {
                dp[i+1][j] = true;
            }
            else if (j >= A[i+1]) {
                if (dp[i][j-A[i+1]])
                dp[i+1][j] = true;
            }
            else {
                dp[i+1][j] = false;
            }
        }
    }
    for (int q : Q) {
        if (dp[aSize-1][q]) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}