#include<bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int n, k;
		cin >> n >> k;
		//unordered_map<int, int> um;
		int ans = 1;
		//for(int i = 2; i < n/i; i++){  小于等于 
		for(int i = 2; i <= n/i; i++){
			/*if(n % i == 0){
				int t = 0;
				while(n/i){
					n /= i;
					t ++;
				}*/
				int t = 0;
				while (n % i == 0){
					t ++;
					n /= i;
				}
				//um[i] = t;
				if(t >= k){
					//for(int i = 0; i < t; i++){
					for(int j = 0; j < t; j++){
						ans *= i;
					}
				}
		} 
		if(n){
			//um[n] = 1;
			if(1 >= k) ans *= n;		
		}
		cout << ans << endl;
	}
	return 0;
}
