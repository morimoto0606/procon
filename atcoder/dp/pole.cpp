#include <iostream>
#include <vector>
using namespace std;


using ll = long long;
const ll INF = 1LL << 60; //2^60;

int main() {
    size_t N;
    cin >> N;
    vector<ll> a(N);
    for (auto& x : a) {
        cin >> x;
    }
    vector<ll> v(N, INF);
    v[0] = 0;
    v[1] = abs(a[1] - a[0]);
    for (int i = 2; i < N; ++i) {
        v[i] = min(v[i-1] + abs(a[i] - a[i-1]),
                   v[i-2] + abs(a[i] - a[i-2]));
    }
    std::cout << v.back() << std::endl;
    return 0;
}