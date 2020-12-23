#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string S;
    cin >> S;
    if (S.back() != 's') {
        cout << S + 's' << endl;
    }
    else {
        cout << S + 'e' + 's' << endl;
    }

}