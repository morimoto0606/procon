#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool smaller(const pair<int, int>& x, const pair<int, int>& y) {
    return x.second < y.second;
}

int main() {
    int H, W, M;
    cin >> H >> W >> M;
    map<int, int> rowMap;
    map<int, int> colMap;
    map<pair<int, int>, int> mat;
    for (int i = 0; i < M; ++i) {
        int h, w;
        cin >> h >> w;
        ++rowMap[h];
        ++colMap[w];
        ++mat[make_pair(h, w)];
    }
    vector<pair<int, int>> row;
    vector<pair<int, int>> col;
    vector<int> rowVec;
    vector<int> colVec;
    row.reserve(H);
    rowVec.reserve(H);
    col.reserve(W);
    colVec.reserve(W);
    for (auto x : rowMap) {
        row.push_back(x);
        rowVec.push_back(x.second);
    }
    for (auto x : colMap) {
        col.push_back(x);
        colVec.push_back(x.second);
    }

    sort(row.begin(), row.end(), smaller);
    sort(col.begin(), col.end(), smaller);
    sort(rowVec.begin(), rowVec.end());
    sort(colVec.begin(), colVec.end());

    auto maxRowSize = distance(lower_bound(rowVec.begin(), rowVec.end(), rowVec.back()), rowVec.end());
    auto maxColSize = distance(lower_bound(colVec.begin(), colVec.end(), colVec.back()), colVec.end());

    if (maxRowSize * maxColSize > M) {
        cout << row.back().second + col.back().second << endl;
        return 0;
    }
    else {
        for (auto i = 0; i < maxRowSize; ++i) {
            for (auto j = 0; j < maxColSize; ++j) {
                auto idR = row[row.size() - maxRowSize + i].first;
                auto idC = col[col.size() - maxColSize + j].first;
                if (mat[make_pair(idR,idC)] == 0)  {
                    cout << row.back().second + col.back().second << endl;
                    return 0;
                }
            }
        }
    }
    cout << row.back().second + col.back().second - 1 << endl;
    return 0;
 
}