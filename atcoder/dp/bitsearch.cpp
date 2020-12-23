#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    for (int tmp = 0; tmp < (1 << 20); ++tmp) {
        bitset<20> s(tmp);

        int sum = 0;
        //2^N 通りすべてのパターンをチェックする（各数字が入っているかいないかのパターン）
        for (int i = 0; i < N; ++i) {
            if (s.test(i)) {
                sum += A.at(i);
            }
        }
        if (sum == K) {
            cout << "True" << endl;
            return 0;
        }
    }

    cout << "False" << endl;
    return 0;
}