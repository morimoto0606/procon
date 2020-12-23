#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int, int> operator+(const pair<int, int>& x, const pair<int, int>& y) {
    return make_pair(x.first+y.first, x.second+y.second);
}
pair<int, int> plusHW(const pair<int, int>& x, const pair<int, int>& y, const int H, const int W) {
    return make_pair(min(max(1, x.first+y.first), H), min(max(1,x.second+y.second), W));
}

int main() {
    int H, W;
    cin >> H >> W;
    int Ch, Cw;
    cin >> Ch >> Cw;
    int Dh, Dw;
    cin >> Dh >> Dw;
    vector<vector<string>> S(H+1, vector<string>(W+1));
    vector<vector<bool>> wallOrVisited(H+1, vector<bool>(W+1));
    for (int h = 1; h <= H; ++h) {
        string str;
        cin >> str;
        for (int w = 1; w <= W; ++w) {
            S[h][w] = str[w-1];
            wallOrVisited[h][w] = (S[h][w] == "#");
        } 
    }
    vector<vector<int>> A(H+1, vector<int>(W+1, -1));
    queue<pair<int, int>> I;
    queue<pair<int, int>> R;
    vector<pair<int, int>> oneStep{{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<pair<int, int>> jump;
    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            jump.push_back(make_pair(i, j));
        }
    }
    jump.erase(find(jump.begin(), jump.end(), make_pair(0,0)));
    for (auto x : oneStep) {
        jump.erase(find(jump.begin(), jump.end(), x));
    }


    wallOrVisited[Ch][Cw] = true;
    I.push(make_pair(Ch, Cw));
    int stage = 0;
    while(!I.empty()) {
        while (!I.empty()) 
        {
            auto x = I.front();
            I.pop();
            R.push(x);
            for (auto d : oneStep) {
                auto y = plusHW(x, d, H, W);
                if (!wallOrVisited[y.first][y.second]) {
                    A[y.first][y.second] = stage;
                    I.push(y); wallOrVisited[y.first][y.second] = true;
                }
            }
        }
        ++stage;
        while(!R.empty()) {
            auto r = R.front();
            R.pop();
            for (auto d : jump) {
                auto x = plusHW(r, d, H, W);
                if (!wallOrVisited[x.first][x.second]) {
                    A[x.first][x.second] = stage;
                    I.push(x);
                    wallOrVisited[x.first][x.second] = true;
                }
            }
        }
    }
    cout << A[Dh][Dw] << endl;

   
}