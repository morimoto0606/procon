#include <bits/stdc++.h>
using namespace std;

void dfs(int u,
    int& time,
    vector<int>& color,
    vector<int>& f,
    vector<int>& d,
    vector<vector<bool>>& M) {
    color[u] = 1;
    d[u] = ++time;
    for (int v = 0; v < M.size(); ++v) {
        if(M[u][v] && color[v] == 0) {
            dfs(v, time, color, f, d, M);
        }
    }
    color[u] = 2;
    f[u] = ++time;
}

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> M(n, vector<bool>(n));
    vector<int> color(n);
    vector<int> f(n);
    vector<int> d(n);
 
    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;
        int size;
        cin >> size;
        for (int j = 0; j < size; ++j) {
            int k;
            cin >> k;
            M[i][k-1] = true;
        }
    }
    int time = 0;
    dfs(0, time, color, f, d, M);
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;
    }


}