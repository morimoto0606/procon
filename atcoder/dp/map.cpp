#include <iostream>
#include <vector>
#include <math.h>
#include <map>
using ll = long long;

using namespace std;
template <typename T>
inline T log(int a, T b) {
    return log(b) / log(a);
}
const vector<string> abc {
    "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"
};
int main() {
    ll N;
    cin >> N;
    ll ord = log(26, N);
    vector<int> p(ord + 1);
    for (ll i = 0; i < ord; ++i) {
        ll q = ord - i;
        ll res = N % (ll)pow(26, q);
        p[q] = (N-res) / (ll)pow(26, q);
        N = res;
    }
    p[0] = N;
    string name = "";
    for (int i : p) {
        if (i==0) {name = }
        name = abc[i-1] + name;
    }
    std::cout << name << endl;
 
    return 0;
}