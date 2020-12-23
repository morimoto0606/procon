#include <iostream>
#include <vector>

int main() {
    int a, b, c, x;
    std::cin >> a >> b >> c >> x;
    const int target = x / 50;

    int count = 0;
    for (int i = 0; i <= a; ++i) {
        const int targetA = target - (10 * i);
        if (targetA < 0) {continue;}
        for (int j = 0; j <= b; ++j) {
            const int targetB = targetA - (2 * j);
            if (targetB < 0) {continue;}
            for (int k = 0; k <= c; ++k) {
                const int targetC = targetB - k;
                if (targetC == 0) {
                    ++count;
                }
                else {continue;}
            }
        }
    } 
    std::cout << count << std::endl;
    return 0;
}