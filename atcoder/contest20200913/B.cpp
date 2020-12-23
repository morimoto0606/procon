#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<ll> x;
    x.push_back(a * c);
    x.push_back(a * d);
    x.push_back(b * c);
    x.push_back(b * d);

    cout << *max_element(x.begin(), x.end()) << endl;

}