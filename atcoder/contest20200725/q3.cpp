#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t N, K;
    cin >> N >> K;
    vector<size_t> A(N+1);
    for (size_t i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    for (size_t i = K+1; i <= N; ++i) {
        if (A[i] > A[i-K]) {
            cout << "Yes" << endl;
        }
        else {cout << "No" << endl;}
    }
    return 0;
}