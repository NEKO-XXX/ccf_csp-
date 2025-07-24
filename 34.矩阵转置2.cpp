#include<bits/stdc++.h>
using namespace std;
int n, m, t;

int main(){
	cin >> n >> m >> t;
	vector<int> M(n*m);
	for(auto& i : M){
		cin >> i;
	}
	while(t--){
		int op, a, b;
		cin >> op >> a >> b;
		//bool f = false;
		if(op == 1){
			n = a; m = b;
		}else if(op == 2){
			vector<int> tmp(n*m);
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					tmp[j*n+i] = M[i*m+j];
				}
			}
			M = tmp;
			swap(n, m);
		}else if(op == 3){
			int idx = a*m + b;
			cout << M[idx] << endl;
		}
	}
	return 0;
}
