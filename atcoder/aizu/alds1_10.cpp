#include <bits/stdc++.h>
using namespace std;

class Fib {
public:
    Fib() : _f1(1), _f2(1) {}
    int operator()(int n) {
        if (n == 0) {
            return _f1;
        }
        if (n == 1) {
            return _f2;
        }
        else {
            for (int i = 2; i <=n; ++i) {
                double x = _f1 + _f2;
                _f1 = _f2;
                _f2 = x;
            }
            return _f2;
        }
    }

private:
    int _f1;
    int _f2;
    int _x;
};

int main() {
    int n;
    cin >> n;
    Fib f;
    cout << f(n) << endl;
}