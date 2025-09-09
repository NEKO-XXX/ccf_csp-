#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n, k;
	cin >> n >> k;
	unordered_map<int, int> um;
	int cnt = 0;
	while(k--){
		int x, y;
		cin >> x >> y;
		if(y != 0 && um.find(y) == um.end()){
			cnt ++;
		}
		um[x] ++;
	}
	cout << cnt;
	return 0;
} 
