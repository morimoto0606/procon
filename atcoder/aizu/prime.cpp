#include <bits/stdc++.h>
using namespace std;

bool judgePrime(int x) {
    int maxCheck = sqrt(x);
    for(int i = 2; i <= maxCheck; ++i) {
        if (x % i == 0)  {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        int x = 0;
        cin >> x;
        if (judgePrime(x)) {
            ++count;
        }
    }
    cout << count << endl;
}