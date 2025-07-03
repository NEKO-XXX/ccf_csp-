// ������dp[i]����Ϊ�ܷ�ճ���ֵΪi������trueʱ������ֵ��������Ϊi 
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
			// ���Ǻͷ�һһ�������⣺����ÿ����ѡ��ѡ��ֻҪһ��true���� 
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
