#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S, T;
    cin >> S >> T;
    auto lenS = S.length();
    auto lenT = T.length();

    auto count = S.length();
    for (auto i = 0; i <= lenS - lenT; ++i) {
        auto modify = 0;
        for (auto j = 0; j < lenT; ++j) {
            if (S[i+j] != T[j]) {
                ++modify;
            }
        }
        if (modify < count) {
            count = modify;
        }
    }
    cout << count << endl;

}