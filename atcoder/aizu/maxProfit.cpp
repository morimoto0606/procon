#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> R(N);
    for (auto& r : R) {
        cin >> r;
    }
    int minR = R[0];
    int maxProfit = R[1] - minR;
    for (int i = 2; i < N; ++i) {
        if (R[i-1] < minR) {minR = R[i-1];}
        if (maxProfit < R[i] - minR) {maxProfit = R[i] - minR;}
    }

    cout << maxProfit << endl;
}