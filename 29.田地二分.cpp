#include<bits/stdc++.h>
using namespace std;
struct f{
	int c;
	int day;
};
int ans, n, m, k;
f farm[100005];
bool judge(int w){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += (max(0, farm[i].day - w))*farm[i].c;
		if(sum>=m){
			return false;
		}
	}	
	return true;
} 

void ef(int l, int r){
	if(l > r){
		return;
	}
	int mid = (l+r) >> 1;
	if(judge(mid)){
		ans = mid;
		return ef(l,mid-1);
	}else{
		return ef(mid+1,r);
	}
}

int main(){
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	int right = 0;
	for(int i = 0; i < n; i++){
		cin >> farm[i].day >> farm[i].c;
		right = max(right, farm[i].day);
	}
	ef(k, right);
	cout << ans;
	return 0;
}
