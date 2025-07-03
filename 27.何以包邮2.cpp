// 法二：dp[i]定义为能否凑出价值为i，等于true时背包价值和容量都为i 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n, x;
	cin >> n >> x;
	int sum = 0;
	vector<int> book;
	while(n--){
		int a;
		cin >> a;
		book.push_back(a);
		sum += a;
	}
	bool dp[sum+1] = {false};
	dp[0] = true;
	for(auto p : book){
		for(int i = sum; i >= p; i--){
			// dp[i] = dp[i-p];
			// 还是和法一一样的问题：对于每本书选或不选，只要一个true即可 
			dp[i] = dp[i-p] || dp[i]; 
		}
	}
	for(int i = x; i <= sum; i++){
		if(dp[i]){
			cout << i;
			break;
		}
	}
	return 0;
}
