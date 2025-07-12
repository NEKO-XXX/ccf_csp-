// 浮点数精确处理 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin >> k;
	while(k--){
		double u,q,n;
		double z;
		cin >> u >> q >> n;
		z = (n-u) / q;
		stringstream ss;
		ss << fixed << setprecision(0) << z*100; // 将 z*100 的结果以 “保留 0 位小数的固定格式” 写入字符串流 ss 中
		string numstr = ss.str();
		int num = stoi(numstr);
		int i = num / 10 + 1;
		int j = num % 10 + 1;
		cout << i << " " << j << endl; 
	}
	return 0;
} 
