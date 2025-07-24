#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	map<int, int> sum;
	map<int, int> t;
	set<int> s;
	while(n--){
		int l, a;
		cin >> l;
		s.clear();
		while(l--){
			cin >> a;
			s.insert(a);
			sum[a] ++;
		}
		for(int i = 1; i <= m; i++){
			if(s.count(i)){
				t[i] ++;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout << t[i] << " " << sum[i] << endl;
	}
	return 0;
}
