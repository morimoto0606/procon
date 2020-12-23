#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    int D1, D2;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        cin >> D1 >> D2;
        if (D1 == D2) {
            ++count;
        }
        else {
            count = 0;
        }
        if (count == 3) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}