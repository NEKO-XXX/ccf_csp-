#include<bits/stdc++.h>
using namespace std;
//int farm[10002][10002];

int main(){
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, a, b;
	cin >> n >> a >> b;
	int sum = 0;
	for(int i = 0; i < n; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 >= a || y2 <= 0 || x2 <= 0 || y1 >= b){
			continue;
		}
		int len, hei;
		int l, r, upper, lower;
		l = (x1 < 0)? 0 : x1;
		r = (x2 < a)? x2 : a;
		upper = (y2 < b)? y2 : b;
		lower = (y1 > 0)? y1 : 0;
		len = r - l;
		hei = upper - lower;
		sum += len*hei;
	}
	cout << sum;
}
