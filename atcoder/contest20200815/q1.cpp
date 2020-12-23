#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    long cont = 0;
    vector<size_t> rainy;
    for (auto i = 0; i < S.length(); ++i) {
        if (S[i] == 'R') {
            ++cont;
        }
        else {
            rainy.push_back(cont);
            cont = 0;
        }
    }
    rainy.push_back(cont);
    cout << *max_element(rainy.cbegin(), rainy.cend()) << endl;
}