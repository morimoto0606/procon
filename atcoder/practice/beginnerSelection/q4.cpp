#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int size;
    std::cin >> size;
    std::vector<int> v(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> v[i];
    }

    auto check = [](const std::vector<int>& w){
        for (int x : w) {
            if (x % 2 == 1) {
                return false;
            }
        }
        return true;
    };

    int count = 0;
    while(check(v)) {
        std::transform(v.begin(), v.end(), v.begin(), [](int x){return x/2;});
        ++count;
    }
    std::cout << count << std::endl;
    return 0;
}