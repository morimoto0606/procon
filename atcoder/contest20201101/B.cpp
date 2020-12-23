#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N;
    cin >> N;
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        ll a, b;
        cin >> a >> b;
        sum += (b * (b+1) - a * (a - 1))/2;
    }

    cout << sum << endl;
}