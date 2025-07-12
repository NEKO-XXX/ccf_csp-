// 从样例得灵感，bfs，队列 
#include<bits/stdc++.h>
using namespace std;
struct d{
	int x;
	int y;
	int l;
};
int main(){
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	int area[110][110];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			area[i][j] = 0;
		}
	}
	queue<d> q;
	d start;
	start.x = x;
	start.y = y;
	start.l = 0;
	area[x][y] = 1;
	q.push(start);
	while(!q.empty()){
		d loc = q.front();
		q.pop();
		int x = loc.x;
		int y = loc.y;
		int step = loc.l;
		if(step >= k) continue;
		if(((x-1)>=1)&&((x-1)<=n)&&((y-2)>=1)&&((y-2)<=n)){
			if(area[x-1][y-2]==0){
				area[x-1][y-2] = 1;
				loc.x = x-1;
				loc.y = y-2;
				loc.l = step+1;
				q.push(loc);
			}
		}
		if(((x+1)>=1)&&((x+1)<=n)&&((y-2)>=1)&&((y-2)<=n)){
			if(area[x+1][y-2]==0){
				area[x+1][y-2] = 1;
				loc.x = x+1;
				loc.y = y-2;
				loc.l = step+1;
				q.push(loc);
			}
		}
		if(((x+2)>=1)&&((x+2)<=n)&&((y-1)>=1)&&((y-1)<=n)){
			if(area[x+2][y-1]==0){
				area[x+2][y-1] = 1;
				loc.x = x+2;
				loc.y = y-1;
				loc.l = step+1;
				q.push(loc);
			}
		}
		if(((x+2)>=1)&&((x+2)<=n)&&((y+1)>=1)&&((y+1)<=n)){
			if(area[x+2][y+1]==0){
				area[x+2][y+1] = 1;
				loc.x = x+2;
				loc.y = y+1;
				loc.l = step+1;
				q.push(loc);
			}
		}
		if(((x+1)>=1)&&((x+1)<=n)&&((y+2)>=1)&&((y+2)<=n)){
			if(area[x+1][y+2]==0){
				area[x+1][y+2] = 1;
				loc.x = x+1;
				loc.y = y+2;
				loc.l = step+1;
				q.push(loc);
			}
		}
		if(((x-2)>=1)&&((x-2)<=n)&&((y+1)>=1)&&((y+1)<=n)){
			if(area[x-2][y+1]==0){
				area[x-2][y+1] = 1;
				loc.x = x-2;
				loc.y = y+1;
				loc.l = step+1;
				q.push(loc);
			}
		}
		if(((x-1)>=1)&&((x-1)<=n)&&((y+2)>=1)&&((y+2)<=n)){
			if(area[x-1][y+2]==0){
				area[x-1][y+2] = 1;
				loc.x = x-1;
				loc.y = y+2;
				loc.l = step+1;
				q.push(loc);
			}
		}
		if(((x-2)>=1)&&((x-2)<=n)&&((y-1)>=1)&&((y-1)<=n)){
			if(area[x-2][y-1]==0){
				area[x-2][y-1] = 1;
				loc.x = x-2;
				loc.y = y-1;
				loc.l = step+1;
				q.push(loc);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(area[i][j] == 1){
				ans ++;
			}
		}
	}
	cout << ans;
	return 0;
} 
