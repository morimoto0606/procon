#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<pair<ll, int>> fac;
    for (ll p = 2; p * p <= N; ++p) {
        if (N % p != 0) continue;
        int index = 0;
        while (N % p == 0)
        {
            ++index;
            N /= p;
        }
        fac.push_back(make_pair(p, index));
    }
    if (N != 1) {
        fac.push_back(make_pair(N, 1));
    }
    
    for (const auto& x : fac) {
        cout << x.first << ", " << x.second << endl;
    }


    return 0;
}