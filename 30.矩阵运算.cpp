#include<bits/stdc++.h>
using namespace std;
int Q[10005][25];
int K[10005][25];
int V[10005][25];
int W[10005];
long long qk[10005][10005];
long long ans[10005][25];

int main(){
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, d;
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= d; j++){
			cin >> Q[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= d; j++){
			cin >> K[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= d; j++){
			cin >> V[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		cin >> W[i];
	}
	for(int i = 1; i <= n; i++){
		for(int k = 1; k <= n; k++){
			cout << qk[i][k] << " ";
		}
		cout << endl;
	}
	for(int i = 1; i <= n; i++){
		for(int k = 1; k <= d; k++){
			for(int j = 1; j <= n; j++){
				qk[i][j] += K[j][k]*Q[i][k];
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int k = 1; k <= d; k++){
			qk[i][k] *= W[i];
		}
	}	
	for(int i = 1; i <= n; i++){
		for(int k = 1; k <= n; k++){
			for(int j = 1; j <= d; j++){
				ans[i][j] += qk[i][k] * V[k][j];
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int k = 1; k <= d; k++){
			cout << ans[i][k] << " ";
		}
		cout << endl;
	}	
	return 0;
} 
