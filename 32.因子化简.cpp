#include<bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin >> q;
	while(q--){
		long long n;
		int k;
		cin >> n >> k;
		unordered_map<int, int> um;
		for(int i = 2; i <= n/i; i++){
			while(n % i == 0){
				// 写成while而不是if，去除所有i的幂次
				um[i] ++;
				n /= i; 
			}
		}
		if(n > 1){
			um[n] ++;
		}
		long long ans = 1;
		for(auto p : um){
			int prime = p.first;
			int cnt = p.second;
			if(cnt >= k){
				for(int j = 0; j < cnt; j++){
					ans *= prime;
				}
			}
		}
		cout << ans << endl;
	}	
	return 0;
}
