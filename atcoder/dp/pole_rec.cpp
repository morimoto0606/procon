#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const ll INF = 1LL << 60; //2^60;

ll value(int i,
    vector<ll>& v,
    const vector<ll>& a) 
{   
    if (v[i] < INF) {return v[i];}
    v[i] = min(value(i-1, v, a) + abs(a[i-1] - a[i]),
               value(i-2, v, a) + abs(a[i-2] - a[i]));
    return v[i];
}

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
    ll result = value(N-1, v, a);
    cout << result << endl;
    return 0;
}