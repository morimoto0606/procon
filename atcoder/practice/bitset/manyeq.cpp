#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    const int length = S.length();
    const int interval = length - 1;
    ll sum = 0;
    string tmp = "";

    for (int i = 0; i < (1 << interval); ++i) {
        bitset<10> b(i);
        vector<ll> split;
        tmp += S[0];
        for (int j = 0; j < interval; ++j) {
            if (b.test(j)) {
                split.push_back(atoll(tmp.c_str()));
                tmp = "";
            }
            tmp += S[j+1];
        }
        split.push_back(atoll(tmp.c_str()));
        tmp = "";
        sum += accumulate(split.cbegin(), split.cend(), 0.0);
    }
    cout << sum << endl;
    return 0;
}