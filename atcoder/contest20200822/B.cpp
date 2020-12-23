#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string N;
    cin >> N;
    ll sum = 0;
    for (int i = 0; i < N.size(); ++i) {
        sum += N[i]-'0';
    }
    if (sum % 9 == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}