#include <bits/stdc++.h>
using namespace std;

class Fib {
public:
    Fib(int n) : _data(n+1) {
        _data[0] = 1;
        _data[1] = 1;
    }

    int operator()(int n) {
        if (n <= _size) {
            return _data[n];
        }
        _data[n] = (*this)(n-1) + (*this)(n-2);
        _size = n;
        return _data[n];
    }

private:
    int _size = 1;
    vector<int> _data;
};


int main() {
    int n;
    cin >> n;
    Fib f(n);
    cout << f(n) << endl;
}