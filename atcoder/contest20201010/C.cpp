#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> P(N);
    for (auto& p : P) {
        cin >> p;
    }
    vector<bool> isAppear(200001);

    ll min = 0;
    auto minPtr = isAppear.begin();
    for (auto p : P) {
        isAppear[p] = true;
        if (p == min) {
            minPtr = find(minPtr, isAppear.end(), false);
            min = distance(isAppear.begin(), minPtr);
        }
        cout << min << endl;
    }

}