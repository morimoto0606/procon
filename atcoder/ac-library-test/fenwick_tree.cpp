#include <atcoder/all>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace atcoder;

int main() {
    

    constexpr size_t size = 1e7;
    fenwick_tree<long> A(size);
    vector<long> B(size);
    
    for (int i = 0; i < size; ++i) {
        A.add(i, i);
        B[i] = i;
    }

    auto start = std::chrono::steady_clock::now();
    auto sumA = A.sum(2, size - 1);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << sumA << " elapsed time: " << elapsed_seconds.count() << "s\n";
 
    long sumB = 0;
    start = std::chrono::steady_clock::now();
    for (int i =2; i < size - 1; ++i) {
        sumB+=B[i];
    }
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << sumB << " elapsed time: " << elapsed_seconds.count() << "s\n";
    
}