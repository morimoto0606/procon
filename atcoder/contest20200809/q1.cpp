#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<double> A(N);
    for (auto& a : A) {
        cin >> setprecision(9) >> a;
    }

    vector<vector<ll>> mat(100, vector<ll>(100));
    for (ll i = 0; i < N; ++i) {
        ll a = (ll)(A[i] * 1e9+0.1);
        int n5 = 0;
        while (a % 5 == 0) {
            a /= 5;
            ++n5;
        }
        int n2 = 0;
        while(a % 2 == 0) {
            a /= 2;
            ++n2;
        }
        mat[n2][n5] += 1;
    }

    vector<vector<ll>> count(100, vector<ll>(100));
    for (int k = 0; k < 100; ++k) {
        for (int l = 0; l < 100; ++l) {
            for (int i = k; i < 100; ++i) {
                for (int j = l; j < 100; ++j) {
                    count[k][l] += mat[i][j];
                }
            }
        }
    }
    
    ll num = 0;
    for (int k = 0; k < 9; ++k) {
        for (int l = 0; l < 100; ++l) {
            num += mat[k][l] * count[18-k][18-l];;
        }
    }
    for (int k = 9; k < 100; ++k) {
        for (int l = 0; l < 9; ++l) {
            num += mat[k][l] * count[9][18-l];
        }
    }
    ll num99 = count[9][9] * (count[9][9] - 1) / 2;
    num += num99;

    cout << num << endl;

}