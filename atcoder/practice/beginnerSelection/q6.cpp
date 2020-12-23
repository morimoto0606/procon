#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
using namespace std;

vector<int> digit10(int n) {
    vector<int> digit10(5);
    for (int i = 0; i <= 4; ++i) {
        const int order = pow(10, 4-i);
        digit10[i] = n / order;
        n = n % order;
    }
    return digit10;
}

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        const auto digit = digit10(i);
        const int sumdigit = std::accumulate(digit.cbegin(), digit.cend(), 0);
        if (A <= sumdigit && sumdigit <= B) {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}