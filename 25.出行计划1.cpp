#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
struct plan{
	int t, c;
};
plan p[200002];
int cha(int q){
	int start = q + k;
	int count = 0;
	for(int i = 1; i <= n; i++){
		if(p[i].t < start){
			continue;
		}else if(p[i].t - start >= p[i].c){
			continue;
		}else{
			count ++;
		}
	}
	return count;
}
int main(){
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> p[i].t >> p[i].c;
	}
	vector<int> query(m+1);
	for(int i = 1; i <= m; i++){
		int q;
		cin >> q;
		query[i] = cha(q);
	}
	for(int i = 1; i <= m; i++){
		cout << query[i] << endl;
	}
	return 0;
}
