#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i, N) cin >> p[i];
    bool dp[101][1002];
    rep(i, N) {
        dp[0][i]=false;
    }
    rep(i, N) dp[i][0] = true;
    
    rep(i, N) {
        if (i == 0) {
            dp[0][p[0]] = true;
            continue;
        }
        else {
            rep(j, 1001) {
                if(dp[i-1][j] || dp[i-1][j-p[i]]) {dp[i][j] = true;}
            }
        }
    }
    int count = 0;
    rep(i, 1001) {
        if (dp[N-1][i]) ++count;
    }
    cout << count << endl;
    
    return 0;
}