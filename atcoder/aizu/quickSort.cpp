#include <bits/stdc++.h>
using namespace std;

int Partition(vector<pair<string, int>>& A, int p, int r)
{
    int x = A[r-1].second;
    int part = p;
    for (int j = p; j < r; ++j) {
        if (A[j].second <= x) {
            iter_swap(A.begin()+part, A.begin()+j);
            ++part;
        }
    }
    return part-1;
}

void quickSort(vector<pair<string, int>>& A, int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        quickSort(A, p, q);
        quickSort(A, q+1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> A(n);
    for (auto& a : A) {
        cin >> a.first >> a.second;
    }

    map<int, vector<string>>  org;
    for (auto& a : A) {
        if (org.count(a.second) == 0) {
            org.emplace(a.second, vector<string>{a.first});
        }
        else {
            org.at(a.second).push_back(a.first);
        }
    }
    
    quickSort(A, 0, n);

    map<int, vector<string>>  sorted;
    for (auto& a : A) {
        if (sorted.count(a.second) == 0) {
            sorted.emplace(a.second, vector<string>{a.first});
        }
        else {
            sorted.at(a.second).push_back(a.first);
        }
    }

    bool stable = true;
    for (const auto& o : org) {
        for (int i = 0; i < o.second.size(); ++i) {
            if (o.second[i] != sorted.at(o.first)[i]) {
                stable = false;
            }
        }
    }

    if (stable) {
        cout << "Stable" << endl;
    }
    else {
        cout << "Not stable" << endl;
    }
    for (const auto& a : A) {
        cout << a.first << " " << a.second << endl;
    }
}