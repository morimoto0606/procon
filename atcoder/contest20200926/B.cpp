#include  <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    if (D < A) {
        cout << "No" << endl;
        return 0;
    }
    else if (B < C) {
        cout << "No" << endl;
        return 0;
    }
    else {
        cout << "Yes" << endl;
        return 0;
    }
}
