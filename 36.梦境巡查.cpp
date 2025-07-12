// 可以根据案例数开数组，尽量避免下标偏移 
// 题解 https://www.cnblogs.com/luckyblock/p/18596275
// 先手动模拟，再推导出数学关系 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int inf = 1e9;
int a[N], b[N], ans[N];
int c[N], pre[N], suf[N];

int main(){	
	ios :: sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n+1; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	pre[0] = suf[n+2] = -inf;
	for(int i = 1; i <= n+1; i++){
		c[i] = c[i-1] + a[i] - b[i-1];
		pre[i] = max(pre[i-1], c[i]);
	}
	for(int i = n+1; i > 0; i--){
		suf[i] = max(suf[i+1], c[i]);
	}
	for(int i = 1; i <= n; i++){
		ans[i] = max(pre[i], suf[i+1] + b[i]);
		cout << max(ans[i], 0) << " ";
	}
	return 0;
} 
