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
	int dp[sum - x + 1] = {0};
	// 背包的重量也就是背包的价值 
	/*for(auto price : book){
		for(int i = sum-x; i >= 0; i--){
			if(i >= price){
			// 写法有误，01背包从左上和正上取最大值 
				dp[i] = dp[i-price] + price;
			}
		}
	}*/
	for(auto price : book){
		for(int i = sum-x; i >= price; i--){
			dp[i] = max(dp[i-price] + price, dp[i]);
		}
	}
	// 输出逻辑有误 1.if没有加break，会不断输出 2.直接输出sum - dp[sum-x]即可
	// dp[i]定义：容量不超过i时最大价值 
	/*for(int i = sum-x; i >= 0; i--){
		if(dp[i]){
			cout << sum - i;
		}
	}*/
	cout << sum - dp[sum-x];
	return 0;
} 
