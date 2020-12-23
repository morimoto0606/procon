#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() 
{
    COMinit();
    const ll mod = 1e9 + 7;
    ll S;
    cin >> S;
    if (S < 3) {
        cout << 0 << endl;
        return 0;
    }
    const ll maxLength = S / 3;
    ll count = 0;
    for (auto i = 1; i <= maxLength; ++i) {
        auto m = S - 2 * i;
        if (i == 1) {
            count += 1;
        }
        else {
            count += COM(m-1, i-1);
        }
        count %= mod;
    }
    cout << count << endl;
}