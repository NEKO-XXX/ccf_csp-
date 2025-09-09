#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 +5;
int n, m, k;
int b[N];

void insert(int l, int r){
	b[l] ++;
	b[r+1] --;
}
int main(){
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		int t, c;
		cin >> t >> c;
		// left变量在定义时不能用自身作为条件判断的结果
		// int left = (t-c+1>0) ? left : 1;
		int left = t-c+1;
		left = left > 0 ? left : 1;
		insert(left, t);
	}
	for(int i = 1; i <= N; i++){
		b[i] = b[i-1] + b[i];
	}
	while(m--)
    {
        int x;
        cin>>x;
        cout<<b[x+k]<<endl;//直接得到x+k处的数值
    }
    return 0;
}
