#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<long> L(N);
    for (auto& l : L) {
        cin >> l;
    }
    sort(L.begin(), L.end());
    auto LL = L;
    auto it = unique(LL.begin(), LL.end());
    LL.erase(it, LL.end());
    vector<int> countL(LL.size());
    for (int i = 0; i < LL.size(); ++i) {
        countL[i] = count(L.begin(), L.end(), LL[i]);
    }

    ll count = 0;
    for (int i = 0; i < LL.size(); ++i) {
        for (int j = i + 1; j < LL.size(); ++j) {
            for (int k = j + 1; k < LL.size(); ++k) {
                if (LL[i] + LL[j] > LL[k]) {
                    count += countL[i] * countL[j] * countL[k];
                }
            }
        }
    }
    cout << count << endl;
}