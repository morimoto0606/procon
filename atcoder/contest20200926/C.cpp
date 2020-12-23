#include  <bits/stdc++.h>
using namespace std;
using ll = long long;

void connectCite(
    int p,
    const vector<vector<int>>& graph,
    vector<bool>& status)
{
    queue<int> Q;
    Q.push(p);
    status[p] = true;
    while (!Q.empty())
    {  
        int k = Q.front();
        Q.pop();
        for (const auto& q : graph[k]) {
            if (!status[q]) {
                Q.push(q);
                status[q] = true;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    vector<bool> status(N);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        graph[A-1].push_back(B-1);
        graph[B-1].push_back(A-1);
    }
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (!status[i]) {
            connectCite(i, graph, status);
            ++count;
        }
    }
    cout << count - 1 << endl;
}
