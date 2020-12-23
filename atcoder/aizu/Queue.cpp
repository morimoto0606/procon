#include <bits/stdc++.h>
using namespace std;


vector<pair<string, int>> roundRobin(
    int q,
    const vector<string>& names, 
    const vector<int>& times) 
{
    queue<pair<string, int>> tasks;
    for (int i = 0; i < names.size(); ++i) {
        tasks.push(make_pair(names[i], times[i]));
    }
    vector<pair<string, int>> finished;
    finished.reserve(names.size());
    int time = 0;
    while(!tasks.empty()) {
        const pair<string, int>& v = tasks.front();
        tasks.pop();
        if (v.second > q) {
            time += q;
            tasks.push(make_pair(v.first, v.second - q));
        }
        else {
            time += v.second;
            finished.push_back(make_pair(v.first, time));
        }
    }
    return finished;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<string> names(n);
    vector<int> times(n);

    for (int i = 0; i < n; ++i) {
        cin >> names[i] >> times[i];
    }
    auto res = roundRobin(q, names, times);
    for (const auto& r : res) {
        cout << r.first << " " << r.second << endl;
    }
}
