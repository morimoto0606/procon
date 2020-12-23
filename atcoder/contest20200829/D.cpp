#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> BreadthFirst(const vector<vector<int>>& graph) 
{
    auto N = graph.size();
    vector<bool> isChecked(N);
    vector<vector<int>> connectedGraph;

    for (int i = 0; i < N; ++i) {
        if (!isChecked[i]) {
            queue<int> Q;
            Q.push(i);
            isChecked[i] = true;
            vector<int> v;
            while (!Q.empty()) {
                auto q = Q.front();
                Q.pop();
                v.push_back(q);
                for (int x : graph[q]) {
                    if(!isChecked[x]) {
                        Q.push(x);
                        isChecked[x] = true;
                    }
                }
            }
            connectedGraph.push_back(v);
        }
    }
    return connectedGraph;
}

vector<vector<int>> DepthFirst(vector<vector<int>>& graph) 
{
    auto N = graph.size();
    vector<bool> isChecked(N);
    vector<vector<int>> connectedGraph;

    for (int i = 0; i < N; ++i) {
        if (!isChecked[i]) {
            stack<int> S;
            S.push(i);
            isChecked[i] = true;
            vector<int> v;
            while (!S.empty()) {
                auto q = S.top();
                if (!graph[q].empty()) {
                    auto it = graph[q].begin();
                    if (!isChecked[*it]) {
                        S.push(*it);
                        isChecked[*it] = true;
                    }
                    graph[q].erase(it);
                }
                else {
                    v.push_back(q);
                    S.pop();
                }
            }
            connectedGraph.push_back(v);
        }
    }
    return connectedGraph;
}


int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        graph[A-1].push_back(B-1);
        graph[B-1].push_back(A-1);
    }
    for (auto& v : graph) {
        sort(v.begin(), v.end());
        auto it = unique(v.begin(), v.end());
        v.erase(it, v.end());
    }
    auto connection = DepthFirst(graph);
    int size = 0;
    for (const auto& v : connection) {
        size = max<int>(size, v.size());
    }
    cout << size << endl;
}