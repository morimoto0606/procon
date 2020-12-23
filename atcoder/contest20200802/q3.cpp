#include <bits/stdc++.h>
using namespace std;

long long seven(long n) {
    long l = 0;
    for (long i = 0; i < n; ++i) {
        l += 7 * pow(10, i);
    }
    return l;
}

long order(long x) {
    return log(x) / log(10) + 1;
}

int main() {
    long K;
    cin >> K;
    long a = 0;
    long b = order(K);
    long long l = seven(b);

    if (l >= K) {
        a = b;
    }
    else {
        a = b+1;
        l =seven(a);
    }
    
    for (int i = 0; i < K; ++i) {
        long r = l % K;
        if (r == 0) {
            cout << a << endl;
            return 0;
        }
        else {
            long long c = order(r);
            l = r * pow(10, b-c) + seven(b-c);
            if (l >= K) {
                a += b - c;
            }
            else {
                a += b - c + 1;
                l = r * pow(10, b-c+1) + seven(b-c+1);
            }
        }
    }
    cout << -1 << endl;

    return 0;
}