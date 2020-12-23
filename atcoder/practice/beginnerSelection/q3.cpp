#include <iostream>

int main() {
    std::string s;
    std::cin >> s;
    int count = 0;
    for (int i = 0; i < 3; ++i) {
        if (s[i] == '1') {
            ++count;
        }
    }
    std::cout << count << std::endl;
    return 0;
}