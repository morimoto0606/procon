#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    double Sx, Sy, Gx, Gy;
    cin >> Sx >> Sy >> Gx >> Gy;
    if (Sx == Gx) {
        cout << Sx << endl;
    }
    else {
        double x = Sx + (Gx-Sx) / (Gy + Sy) * Sy;
        cout << setprecision(10) <<  x;
    }


}