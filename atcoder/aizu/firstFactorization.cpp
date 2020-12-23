#include <bits/stdc++.h>
using namespace std;

std::vector<int> minPrimes(int n) {
    vector<int> res(n);
    iota(res.begin(), res.end(), 0);
    for (int i = 2; i * i < n; ++i) {
        if (res[i] < i) {
            //not prime
            continue;
        }
        for (int j = i * i; j < n; j+=i) {
            if (res[j] ==j) {
                res[j] = i;
            }
        }
    }
    return res;
}

std::vector<int> factrize(int n) {
    auto vecP = minPrimes(n+1);
    vector<int> res;
    while(n > 1) {
        int d = vecP[n];
        n /= d;
        res.push_back(d);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    auto res = factrize(n);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
}
