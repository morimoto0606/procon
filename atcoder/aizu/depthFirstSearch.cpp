#include <bits/stdc++.h>
using namespace std;

pair<vector<int>, vector<int>> dfs(vector<vector<int>>& graph) 
{
    int time = 1;
    stack<int> stack;
    vector<int> arrivalTime(graph.size());
    vector<int> leaveTime(graph.size());

    stack.push(0);
    arrivalTime[0] = time;
    while (stack.size() > 0)
    {
        ++time;
        int k = stack.top();
        auto edgeIt = find(graph[k].begin(), graph[k].end(), 1);
        if (edgeIt == graph[k].end()) {
            stack.pop();
            leaveTime[k] = time;
        }
        else {
            int v = distance(graph[k].begin(), edgeIt);
            stack.push(v);
            arrivalTime[v] = time;
            for (auto& g : graph) {
                g[v] = 0;
            }
        }
    }
    return make_pair(arrivalTime, leaveTime);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    graph.reserve(n);
    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;
        int size;
        cin >> size;
        for (int j = 0; j < size; ++j) {
            int k;
            cin >> k;
            graph[i][k-1] = 1;
        }
    }

    auto&& result = dfs(graph);
    for (int i = 0; i < n; ++i) {
        cout << i+ 1 << " " << result.first[i] << " " << result.second[i]<< endl;
    }
}