#include <iostream> 
#include <vector>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    vector<int> a(A), b(B);
    for (int& x : a) {
        cin >> x;
    }
    for (int& x : b) {
        cin >> x;
    }

    vector<vector<int>> dp(A+1, vector<int>(B+1));
    for (int i = A; i >= 0; --i) {
        for (int j = B; j >= 0; --j) {
            if ((i+j) % 2 == 0) {
                if (i==A && j==B) {
                    continue;
                }
                else if (i==A) {
                    dp[i][j] = dp[i][j+1]+b[j];
                }
                else if (j==B) {
                    dp[i][j] = dp[i+1][j]+a[i];
                }
                else {
                    dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j+1]+b[j]);
                }
            }
            else {
                if(i==A && j==B) {
                    continue;
                }
                else if (i==A) {
                    dp[i][j] = dp[i][j+1];
                }
                else if (j==B) {
                    dp[i][j] = dp[i+1][j];
                }
                else {
                    dp[i][j] = min(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
