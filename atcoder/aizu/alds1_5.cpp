#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool rec(int target, const vector<int>& A) {
    if (target == 0) {
        return true;
    }
    if (A.size() > 1) {
        vector<int> A1(A.begin(), A.end()-1);
        if (rec(target, A1)) {
            return true;
        }
        if (rec(target-A.back(), A1)) {
            return true;
        }
    }
    else {
        if (target == A.back()) {
            return true;
        }
    }
    return false;
}

int main() {
    int aSize;
    cin >> aSize;
    vector<int> A(aSize);
    for (auto&& a : A) {
        cin >> a;
    }

    int qSize;
    cin >> qSize;
    vector<int> Q(qSize);
    for (auto&& q : Q) {
        cin >> q;
    }

    for (int q : Q) {
        const bool result = rec(q, A);
        if (result) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

}