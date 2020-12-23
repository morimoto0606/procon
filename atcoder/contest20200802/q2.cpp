#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    double D;
    cin >> N >> D;

    vector<vector<double>> p(N, vector<double>(2));
    for (auto& v : p) {
        cin >> v[0] >> v[1];
    }
    int count = 0;
    for (const auto& v : p) {
        if (pow(v[0], 2.0) + pow(v[1], 2.0) <= pow(D, 2.0)) {
            ++ count;
        }
    }
    cout << count << endl;

    return 0;
}