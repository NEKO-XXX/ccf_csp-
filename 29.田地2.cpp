#include<bits/stdc++.h>
using namespace std;
int main(){
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m, k;
	cin >> n >> m >> k;
	priority_queue<pair<int, int>> pq;
	for(int i = 0; i < n; i++){
		int t, c;
		cin >> t >> c;
		pq.emplace(t, c);
	}
	while(m - pq.top().second>= 0 && pq.top().first > k){
		int day = pq.top().first, s = pq.top().second;
		m -= s;
		pq.pop();
		pq.emplace(day-1, s);
	}
	cout << pq.top().first;
	return 0;
} 
