#include <bits/stdc++.h>
using namespace std;

int main() {
    bitset<10> a("1010010001"); // 1 3 6 10
    bitset<10> b("0110101101"); //2 3 5 7 8 10
    auto c = a & b;
    cout << c << endl;

    for (int tmp = 0; tmp < (1 << 3); ++tmp) {
        bitset<3> s(tmp);
        cout << s << endl;
    }
    return 0;
}