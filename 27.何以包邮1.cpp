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
	// ����������Ҳ���Ǳ����ļ�ֵ 
	/*for(auto price : book){
		for(int i = sum-x; i >= 0; i--){
			if(i >= price){
			// д������01���������Ϻ�����ȡ���ֵ 
				dp[i] = dp[i-price] + price;
			}
		}
	}*/
	for(auto price : book){
		for(int i = sum-x; i >= price; i--){
			dp[i] = max(dp[i-price] + price, dp[i]);
		}
	}
	// ����߼����� 1.ifû�м�break���᲻����� 2.ֱ�����sum - dp[sum-x]����
	// dp[i]���壺����������iʱ����ֵ 
	/*for(int i = sum-x; i >= 0; i--){
		if(dp[i]){
			cout << sum - i;
		}
	}*/
	cout << sum - dp[sum-x];
	return 0;
} 
