#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;

vector<int> convert(ll A) {
    vector<int> ret;
    while (A > 10)
    {
        auto m = A % 10;
        ret.push_back(m);
        A -= m;
        A /= 10;
    }
    ret.push_back(A);
    return ret;
}

int main() {
    ll N;
    cin >> N;
    auto A = convert(N);
    for (auto& a : A) {
        a %= 3;
        if (a < 0) {
            a += 3;
        }
    }
    sort(A.begin(), A.end());
    int num2 = count(A.cbegin(), A.cend(), 2);
    int num1 = count(A.cbegin(), A.cend(), 1);
    ll sum = accumulate(A.cbegin(), A.cend(), 0) % 3;
    if (sum == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (sum == 2) {
        if (num2 > 0 && 1 < A.size()) {
            cout << 1 << endl;
            return 0;
        }
        else if (num1 > 1 && 2 < A.size()) {
            cout << 2 << endl;
            return 0;
        }
        else {
            cout << -1 << endl;
            return 0;
        }
    }
    if (sum == 1) {
        if (num1 > 0 && 1 < A.size()) {
            cout << 1 << endl;
            return 0;
        }
        else if (num2 > 1 && 2 < A.size()) {
            cout << 2 << endl;
            return 0;
        }
        else {
            cout << -1 << endl;
            return 0;
        }
    }
}