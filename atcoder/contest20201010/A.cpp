#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    string T;
    cin >> T;

    if (S == "Y") {
        if (T == "a") {
            cout << "A" << endl;
        }
        else if (T == "b") {
            cout << "B" << endl;
        }
        else {
            cout << "C" << endl;
        }
    }
    else {
        cout << T << endl;
    }

}