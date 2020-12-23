#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll X, K, D;
    cin >> X >> K >> D;

    X = abs(X);
    ll n = X / D;

    ll distance = 0;
    if (K <= n) {
        distance = X - K * D;
    }
    else {
        ll d1 = X - n * D;
        ll d2 = (n+1) * D - X;
        if (n % 2 == K % 2) {
            distance = d1;
        }
        else {
            distance = d2;
        }
    }
    cout << distance << endl;
}