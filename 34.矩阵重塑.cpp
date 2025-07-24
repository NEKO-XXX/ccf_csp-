#include<bits/stdc++.h>
using namespace std;
int n, m, p, q;

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> p >> q;
    vector<int> M(n*m);
    for(auto& i : M){
    	cin >> i;
	}
	for(int i = 0; i < n*m; i++){
		cout << M[i] << " ";
		if((i+1)%q==0){
			cout << endl;
		} 
	}
    return 0;
}
