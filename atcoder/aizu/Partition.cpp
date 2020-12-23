#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int>& A, int p, int r)
{
    int x = A.back();
    int part = p;
    for (int j = p; j < r; ++j) {
        if (A[j] <= x) {
            iter_swap(A.begin()+part, A.begin()+j);
            ++part;
        }
    }
    return part;
}

int main() {
    int n; 
    cin >> n;
    vector<int> vec(n);
    for (auto& v : vec) {
        cin >> v;
    }
    const int x = vec.back();
    const int partition = Partition(vec, 0, vec.size());
    for (int i = 0; i < n; ++i) {
        if (i == partition - 1) {
            cout << "[" << vec[i] << "]";
        }
        else {
            cout << vec[i];
        }
        if (i < n-1)  {
            cout << " ";
        }
    }
    cout << endl;
}