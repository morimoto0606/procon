#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int N;
    vector<int> d(N);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> d[i];
    }
    std::sort(begin(d), end(d));
 
    const auto point = unique(d.begin(),d.end());
    const int i = point - d.begin() - 1;
    std::cout << i << std::endl;
    return 0;
}