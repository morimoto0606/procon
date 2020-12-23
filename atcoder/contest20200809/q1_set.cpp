#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<double> A(N);
    for (auto& a : A) {
        cin >> a;
    }

    vector<pair<int, int>> order0;
    vector<pair<int, int>> order1;
    vector<pair<int, int>> order2;
    vector<pair<int, int>> order3;

    for (ll i = 0; i < N; ++i) {
        ll a = (ll)(A[i] * 1e9 + 0.1);
        int n5 = -9;
        while (a % 5 == 0) {
            a /= 5;
            ++n5;
        }
        int n2 = -9;
        while(a % 2 == 0) {
            a /= 2;
            ++n2;
        }
        if (n2 < 0 && n5 < 0) {
            order0.push_back(make_pair(n2, n5));
        }
        else if (n2 >= 0 && n5 < 0) {
            order1.push_back(make_pair(n2, n5));
        }
        else if (n2  < 0 && n5 >= 0) {
            order2.push_back(make_pair(n2, n5));
        }
        else {
            order3.push_back(make_pair(n2, n5));
        }
 
    }

    ll num = 0;
    for (const auto& x : order0) {
        int count = count_if(order3.cbegin(), order3.cend(), [&x](const pair<int, int>& y){return (x.first + y.first >=0) && (x.second + y.second >=0);});
        num += count;
    }
    for (const auto& x : order1) {
        int count = count_if(order2.cbegin(), order2.cend(), [&x](const pair<int, int>& y){return x.second + y.second >=0;});
        num += count;
        count = count_if(order3.cbegin(), order3.cend(), [&x](const pair<int, int>& y){return (x.first + y.first >=0) && (x.second + y.second >=0);});
        num += count;
    }
    for (const auto& x : order2) {
        int count = count_if(order3.cbegin(), order3.cend(), [&x](const pair<int, int>& y){return x.first+ y.first >=0;});
        num += count;
    }
    ll size = order3.size();
    size = size * (size -1)/2;
    num += size;
    cout << num << endl;

}