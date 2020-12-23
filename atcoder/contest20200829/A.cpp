#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    double D, T, S;
    cin >> D >> T >> S;
    double x = D / S;
    if (x <= T) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

}