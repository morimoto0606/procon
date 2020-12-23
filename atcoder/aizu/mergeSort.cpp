#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 2e9;

void merge(int& count, vector<int>& A, int left, int mid, int right)
{
    vector<int> L(A.begin() + left, A.begin() + mid);
    vector<int> R(A.begin() + mid, A.begin() + right);
    L.push_back(INF);
    R.push_back(INF);
    int i = 0;
    int j = 0;
    for (int k = left; k < right; ++ k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            ++i;
        }
        else {
            A[k] = R[j];
            ++j;
        }
    }
    count += (right - left);

}

void mergeSort(int& count, vector<int>& A, int left, int right) 
{
    if (left + 1 < right) {
        const int mid = (left + right) / 2;
        mergeSort(count, A, left, mid);
        mergeSort(count, A, mid, right);
        merge(count, A, left, mid, right);
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> S(n);
    for (auto& s : S) {
        cin >> s;
    }

    int count = 0;
    mergeSort(count, S, 0, n);
    for (int i = 0; i < S.size() - 1; ++i) {
        cout << S[i] << " ";
    }
    cout << S.back() << endl;
    cout << count << endl;

}