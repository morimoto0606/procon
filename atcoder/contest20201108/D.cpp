#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    ll maxPos = 0;
    ll maxMove = 0;
    ll sum = 0;
    ll pos = 0;
    ll A;
    for (int i = 0; i < N; ++i) {
        cin >> A;
        sum += A;
        maxMove = max(sum, maxMove);
        maxPos = max(maxPos, pos + maxMove);
        pos += sum;
    }
    cout << maxPos << endl;
}