#include<bits/stdc++.h>
using namespace std;
struct chess{
	string board[8];
};
chess ch[105];
int appear[105];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		appear[i] = 1;
		for(int j = 0; j < 8; j++){
			cin >> ch[i].board[j];
		}
	}
	for(int i = 2; i <= n; i++){
		for(int j = i-1; j >= 1; j--){
			bool v = true;
			for(int k = 0; k < 8; k++){
				if(ch[i].board[k] != ch[j].board[k]){
					v = false;
					break;
				}
			}
			if(v){
				appear[i] = appear[j] + 1;
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << appear[i] << endl;
	}
	return 0;
}
