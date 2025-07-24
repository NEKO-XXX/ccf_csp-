#include<bits/stdc++.h>
using namespace std;
int dp[1005][40010];//前i个仓库费用j可以获得的最大总价值
vector<int>a[1005];//第i个仓库的第j个货物的价值
int b[1005],c[1005];//仓库属性
bool dcmp(int a, int b){
	return a > b;
}
int main(){
	int n, m , v;
	cin >> n >> m >> v;
	for(int i=0;i<=40000;i++)dp[0][i]=0;
    for(int i=1;i<=n;i++){
        cin>>b[i]>>c[i];
    }
    for(int i=1;i<=m;i++){
        int val,t;
        cin>>val>>t;
        t++;
        a[t].push_back(val);
    }
    for(int i=1;i<=n;i++){
        sort(a[i].begin(),a[i].end(),dcmp);
    }
    for(int i = 1; i <= n; i++){
    	for(int j = 0; j <= 40000; j++){
    		dp[i][j] = dp[i-1][j];
    		int sum = 0;
    		for(int k = 0; k < a[i].size(); k++){
    			if(b[i]+c[i]*(k+1)>j)break;
				sum += a[i][k];
    			dp[i][j] = max(dp[i][j], dp[i-1][j-b[i]-c[i]*(k+1)] + sum - b[i]-c[i]*(k+1));
			}
		}
	}
	int ans;
	for(int i=0;i<=40000;i++){
        if(dp[n][i]>=v){
            ans=i;break;
        }
    }
    cout<<ans;
    return 0;
}
