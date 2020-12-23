#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    const int c = a * b;
    if (c%2 == 0) {
        std::cout << "Even" << std::endl;
    }
    else {
        std::cout << "Odd" << std::endl;;
    }
    return 0;
}