#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    auto prev = A[0];
    ll sumHeight = 0;
    for (auto i = 1; i < N; ++i) {
        if (A[i] < prev) {
            auto diff = prev - A[i];
            sumHeight += diff;
        }
        else {
            prev = A[i];
        }
    }
    cout << sumHeight << endl;
}