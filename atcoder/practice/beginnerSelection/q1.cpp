#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    int b, c;
    cin >> b >> c;
    const int d = a + b + c;
    string str;
    cin >> str;
    cout << d << " " << str << endl;
    return 0;
}