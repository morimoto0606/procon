#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N+1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i]; 
    }
    size_t port = 0;
    size_t value = 1000;
    for (int i = 1; i <= N-1; ++i) {
        if (A[i+1] - A[i] >= 0) {
            port = value / A[i];
        }
        else {
            port = 0;
        }
        value += port * (A[i+1] - A[i]);
    }
    std::cout << value << endl;
    return 0;
}