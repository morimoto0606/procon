#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, X, T;
    cin >> N >> X >> T;

    if (N % X != 0) {
        cout << (N / X + 1) * T << endl;
    }
    else {
        cout << N / X * T << endl;
    }
}