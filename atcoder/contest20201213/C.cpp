#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    ll L;
    cin >> L;
    for (auto& a : A) {
        cin >> a;
    }
    cout << *min_element(A.cbegin(), A.cend()) << endl;

}