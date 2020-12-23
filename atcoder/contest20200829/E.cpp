#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> minPrimes(int n) {
    vector<int> res(n);
    iota(res.begin(), res.end(), 0);
    for (int i = 2; i*i < n; ++i) {
        if (res[i] < i) {continue;}
        for (int j = i * i; j < n; j += i) {
            if (res[j] == j) {
                res[j] = i;
            }
        }
    }
    return res;
}

map<int, int> factorize(int n, const vector<int>& minPrimes) {
    map<int, int> res;
    while (n > 1) {
        int d = minPrimes[n];
        n /= d;
        ++res[d];
    }
    return res;
}
 
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    int max = *max_element(A.begin(), A.end());
    auto pVec = minPrimes(max+1);
    vector<map<int, int>> factorizes;
    transform(A.cbegin(), A.cend(), back_inserter(factorizes), [&pVec](int a){return factorize(a, pVec);});
    bool hasPair = false;
    bool hasSet = false;
    vector<int> allP;
    for (const auto& f : factorizes) {
        for (const auto& x : f) {
            allP.push_back(x.first);
        }
    }
    sort(allP.begin(), allP.end());
    allP.erase(unique(allP.begin(), allP.end()), allP.end());
    for (int a : allP) {
        int count = 0;
        for (const auto& f : factorizes) {
            if (f.find(a) != f.end()) {
                ++count;
            }
        }
        if (count == N) {
            hasSet = true;
        }
        if (count >= 2) {
            hasPair = true;
        }
    }

    if (!hasPair) {
        cout << "pairwise coprime" << endl;
    }
    else if (!hasSet) {
        cout << "setwise coprime" << endl;
    }
    else {
        cout << "not coprime" << endl;
    }

}