#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N, M, T;
    cin >> N >> M >> T;
    const int maxN = N;
    vector<int> A(M);
    vector<int> B(M);
    for(int i = 0; i < M; ++i) {
        cin >> A[i] >> B[i];
    }
    N -= A[0];
    for (int i = 0; i < M-1; ++i)  {
        if (N <= 0) {
            cout << "No" << endl;
            return 0;
        }
        N += B[i] - A[i];
        N = min(N, maxN);
        N -= A[i+1] - B[i];
 
    }
    if (N <= 0) {
        cout << "No" << endl;
        return 0;
    }
    N += B[M-1] - A[M-1];
    N = min(N, maxN);
 
    N -= T - B[M-1];
    if (N <= 0) {
        cout << "No" << endl;
        return 0;
    }
    else {
        cout << "Yes" << endl;
    }

}