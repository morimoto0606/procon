#include <iostream>

using namespace std;

int main() {
    int X;
    cin >> X;
    if (400 <= X && X <= 599) {
        cout << 8 << endl;
    }
    else if (600 <= X && X <= 799) {
        cout << 7 << endl;
    }
    else if (800 <= X && X <=999 )
    {
        cout << 6 << endl;
    }
    else if (1000 <= X && X <=1199 )
    {
        cout << 5 << endl;
    }
    else if (1200 <= X && X <=1399)
    {
        cout << 4 << endl;
    }
    else if (1400 <= X && X <=1599)
    {
        cout << 3 << endl;
    }
 
     else if (1600<= X && X <=1799 )
    {
        cout << 2 << endl;
    }
    else if (1800 <= X && X <=1999)
    {
        cout << 1 << endl;
    }
    else {cout << "error input" << endl;}

    return 0;
}