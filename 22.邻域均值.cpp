// https://www.acwing.com/problem/content/3415/
// https://leetcode.cn/problems/range-sum-query-2d-immutable/solutions/2667331/tu-jie-yi-zhang-tu-miao-dong-er-wei-qian-84qp/
// 核心：前缀和数组递推式 边界处理 pre[i+1][j+1]表示到a[i][j]的矩阵和 
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	int n, l, r, t;
	cin >> n >> l >> r >> t;
	vector<vector<int>> a(n,vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		} 
	} 
	vector<vector<int>> pre(n+1,vector<int>(n+1, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			// 递推式错误 
			pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + a[i][j];
		} 
	} 
	
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int upper = max(0, j-r); 
			int lower = min(n-1, j+r);
			int left = max(0, i-r);
			int right = min(n-1, i+r);
			int sum = pre[right+1][lower+1] - pre[left][lower+1] - pre[right+1][upper] + pre[left][upper];
			if(sum <= t*(lower-upper+1)*(right-left+1)){
				cnt ++;
			}
		} 
	}
	cout << cnt;
	return 0; 
}
