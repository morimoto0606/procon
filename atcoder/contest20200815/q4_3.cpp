#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> P(N);
    vector<ll> C(N);
    for (auto& p : P) {
        cin >> p;
        --p;
    }
    for (auto& c : C) {
        cin >> c;
    }

    vector<int> isAssigned(N);
    vector<vector<int>> orbits;
    for (int i = 0; i < N; ++i) {
        if (!isAssigned[i]) {
            vector<int> o;
            o.push_back(i);
            int j = i;
            while (P[j] != i)
            {
                o.push_back(P[j]);
                isAssigned[P[j]] = true;
                j = P[j];
            }
            orbits.push_back(o);
        }
    }

    vector<ll> results;
    for (const auto& o : orbits) {
        vector<ll> Co;
        transform(o.cbegin(), o.cend(), back_inserter(Co), [&C](int i){return C[i];});
 
        ll Csum =  accumulate(Co.cbegin(), Co.cend(), (ll)0);
        ll loopNum = Csum > 0 ? max<ll>(K / o.size() - 1, 0) : 0;
        ll Ko = Csum > 0 ? K - loopNum * o.size() : min<ll>(K, o.size());
        
        vector<ll> dp(o.size());
        ll res = *max_element(Co.cbegin(), Co.cend());
        for (auto k = 0; k < Ko; ++k) {
            vector<ll> b;
            transform(Co.cbegin(), Co.cend(), dp.cbegin(), back_inserter(b), [](ll c, ll d){return d + c;});
            copy(b.begin()+1, b.end(), dp.begin());
            dp.back() = b[0];
            res = max(res, *max_element(dp.cbegin(), dp.cend()));
        }
        results.push_back(loopNum * Csum + res);
    }
    ll result =  *max_element(results.cbegin(), results.cend());
    cout << result << endl;
}