// �뵽�˱������⵫��û��д����
// ���ж�01������ȫ �ٽ���׼���������еĲ�������Ŀ�в���һһ��Ӧ 
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for(auto &i : a) {
		cin >> i;
	}
	vector<int> dp(n+1);
	dp[0] = 0;
	for(int i = 0; i < m; i++){
		for(int j = i+1; j <= n; j++){
			dp[j] = max(dp[j], dp[j-i-1] + a[i]); 
		}
	}
	cout << dp[n];
	return 0;
}
