// 不要害怕暴力解法 
#include<bits/stdc++.h>
using namespace std;
const int N = 1010;

int n, m;
int d[N][11];
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> d[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		int fa = 0;
		for(int j = 1; j <= n; j++){
			bool v = true;
			for(int k = 1; k <= m; k++){
				if(d[i][k] >= d[j][k]){
					v = false;
					break;
				}
			}
			if(v){
				fa = j;
				break;
			}
		}
		cout << fa << endl;
	}
	
	return 0;
} 
