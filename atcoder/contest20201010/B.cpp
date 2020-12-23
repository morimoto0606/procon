#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (auto& s : S) {
        cin >> s;
    }
    int count = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W-1; ++j) {
            if (S[i][j] == '.' && S[i][j+1] == '.') {
                ++count;
            }
        }
    }
    for (int i = 0; i < H-1; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S[i][j] == '.' && S[i+1][j] == '.') {
                ++count;
            }
        }
    }
    cout << count << endl;
}