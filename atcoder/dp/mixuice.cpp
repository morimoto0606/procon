#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace  std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> p(N);
    for (auto& x: p) {
        cin >> x;
    }
    sort(p.begin(), p.end());
    int sum = accumulate(p.begin(), p.begin() + K, 0);
    cout << sum << endl;
    return 0;
}