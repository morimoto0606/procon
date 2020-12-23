#include <bits/stdc++.h>
using namespace std;



int main() {
    int X;
    cin >> X;

    for (int A = -200; A < 200; ++A) {
        for (int B = -200; B < A; ++ B) {
            if (pow(A, 5) - pow(B, 5) == X) {
                cout << A << " " << B << endl;
                return 0;
            }
        }
    }

}