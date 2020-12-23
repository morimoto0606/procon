#include <bits/stdc++.h>
using namespace std;

int cutnumber(
    const vector<double>& b,
    double a,
    int k,
    int l) 
{
    if (b[k-l] <= a/(l+1)) {
        return l;
    }
    for (int i = 1; i <= l; ++i) {
        const int idx = l-i+1;
        if(b[k-idx+1] <= a/idx)  {
            if(b[k-idx] < a/idx) {
                return idx;
            }
            else {
                return l-i;
            }
        }
    }
    return 0;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<double> a(N);
  
    for (double& x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end(), greater<int>());
    vector<double> b(K+1);
 
    for (int k = 0; k <= K; ++k) {
        b[k] = (double)a[0] / (k + 1);
    }
 
    vector<int> l(N);
    l[0] = K/2;
    for (int n = 1; n < N; ++n) {
        l[n] = cutnumber(b, a[n], K, l[n-1]);
        b[K] = max(b[K-l[n]], a[n]/(l[n]+1));
        if (l[n] == 0) {
            cout << (int)ceil(b[K]) << endl;
            return 0;
        }
        int m = min(l[n], K / n);
        int r = 0;
        for (int k = K-1; k >= r; --k) {
            m = cutnumber(b, a[n], k, m);
            if (m >=1) {
                b[k] = max(b[k-m], a[n]/(m+1));
            }
            else {
                if (b[k] >= a[n]) {
                    r = k;
                    break;
                }
                else {
                    b[k] = a[n];
                }
            }
        }
    }
    cout << (int)ceil(b[K]) << endl;
    return 0;
}