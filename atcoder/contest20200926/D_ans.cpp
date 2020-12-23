#include <bits/stdc++.h>
#include <atcoder/all>
 
using namespace std;
using namespace atcoder;
 
 
int op(int a, int b){
    return max(a, b);
}
 
int e(){
    return 0;
}
 
int main(void){
	int N,K,x,i,ans=0;
	segtree <int, op, e> seg(300010);
	
	cin >> N >> K;
	for (auto i = 0; i < N; ++i) {
		cin >> x;
		int L = max(x - K, 0);
		int R = min(x + K, 300000);
		int tmp = seg.prod(L, R+1) + 1;
		ans = max(ans, tmp);
		seg.set(x, tmp);
	}
	
	cout << ans << endl;
	return 0;
}