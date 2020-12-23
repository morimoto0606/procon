#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int K;
    cin >> K;

    int i = 0;
    while (B <= A) {
        B*=2;
        ++i;
    }
    if (i > K) {
        cout << "No" << endl;
        return 0;
    }
    while (C <= B) {
        C *= 2;
        ++i;
    }
    if (i > K) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    return 0;
}