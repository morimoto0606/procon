#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;

int countDevide(const vector<int>& A, const int d) {
    int count = 0;
    for (int a : A) {
        if (a % d == 0) {
            ++count;
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    sort(A.begin(), A.end());
    int max = A.back();
    vector<int> D(max+1);

    for (int i = 2; i <= max; ++i) {
        D[i] = countDevide(A, i);
    }
    auto it = max_element(D.begin(), D.end());
    cout << distance(D.begin(), it) << endl;

}