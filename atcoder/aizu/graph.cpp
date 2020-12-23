#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adjMat(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        int row;
        cin >> row;
        int size;
        cin >> size;
        for (int j = 0; j < size; ++j) {
            int k;
            cin >> k;
            adjMat[i][k-1] = 1;
        }
    }

    for (const auto& v : adjMat) {
        for (const auto& x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
} 