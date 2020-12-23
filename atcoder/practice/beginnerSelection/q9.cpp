#include <iostream>

using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;
    Y /= 1000;
    for (int m = 0; m <= min(Y/5, 400); ++m) {
        const int z = Y % 5 + 5 * m;
        const int y = 2 * N - 2 * z - (Y-z) / 5;
        const int x = N - y - z;
        if (x >= 0 && y >= 0) {
            std::cout << x << " " << y << " " << z << std::endl;
            return 0;
        }
        else {
            continue;
        }
       
    }
    std::cout << -1 << " " << -1 << " " << -1 << std::endl;
    return 0;
}