#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    const int AMAX = sqrt(N);
    long count = 0;
    for (int A = 1; A <= AMAX; ++A) {
        for (int B = A + 1; A * B < N; ++B) {
            ++count;
        }
    }
    count *=2;
    for (int A = 1; A <= AMAX; ++A) {
        if (A * A < N) {
            ++count;
        }
    }
    cout << count << endl;
}