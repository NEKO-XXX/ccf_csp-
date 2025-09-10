#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
struct order{
	int matrix[4] = {-1};
	int type;
};
order o[100002];
deque<array<int, 4>> dq;
int n, m;

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int v;
		cin >> v;
		o[i].type = v;
		if(v!=3){
			cin >> o[i].matrix[0] >> o[i].matrix[1] >> o[i].matrix[2] >> o[i].matrix[3];
			//ti.push(i);
		}
	}
	while(m--){
		int v;
		cin >> v;
		if(v == 1){
			int i;
			cin >> i;
			if(o[i].type != 3){
				cin >> o[i].type >> o[i].matrix[0] >> o[i].matrix[1] >> o[i].matrix[2] >> o[i].matrix[3];
			}
		}else{
			int l, r;
			cin >> l >> r;
			stack<int> ti;
			dq.clear();
			for(int i = l; i <= r; i++){
				int t = o[i].type;
				if(t = 1){
					array<int, 4> arr = {o[i].matrix[0],o[i].matrix[1],o[i].matrix[2],o[i].matrix[3]};
					dq.push_front(arr);
					ti.push(i);
				}else if(t == 2){
					array<int, 4> arr = {o[i].matrix[0],o[i].matrix[1],o[i].matrix[2],o[i].matrix[3]};
					dq.push_back(arr);
					ti.push(i);
				}else if(t == 3){
					int idx = ti.top();
					ti.pop();
					if(o[idx].type == 1){
						dq.pop_front();
					}else{
						dq.pop_back();
					}
				}
			}
			if(dq.empty()){
				cout << 1 << " " << 0 << " " << 0 << " " << 1 << endl;
				continue;
			}
			int ans[4] = {1, 0, 0, 1};
			while(!dq.empty()){
				array<int, 4> a = dq.front();
				dq.pop_front();
				int m1 = ans[0]*a[0] + ans[1]*a[2];
				int m2 = ans[0]*a[1] + ans[1]*a[3];
				int m3 = ans[2]*a[0] + ans[3]*a[2];
				int m4 = ans[2]*a[1] + ans[3]*a[3];
				ans[0] = m1;
				ans[1] = m2;
				ans[2] = m3;
				ans[3] = m4;
			}
			cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
		}
	}
	return 0;
}
