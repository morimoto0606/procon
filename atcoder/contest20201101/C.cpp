#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> P(N);
    for (auto& p : P) {
        cin >> p.first >> p.second;
    }
    bool exits = false;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            double kx = (P[j].first-P[i].first);
            double ky = (P[j].second-P[i].second);
            for (int k = j+1; k < N; ++k) {
                double vx = P[k].first - P[i].first;
                double vy = P[k].second - P[i].second;
                if (kx == 0) {
                    if (vx == 0) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
                else {
                    double a = ky / kx;
                    if (vy == a * vx) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }

    }
    cout << "No" << endl;
}