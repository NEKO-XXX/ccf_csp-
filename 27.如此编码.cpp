#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// �Ҵ���ǰ����һ�ζδ����ң���������Ǵ����߼���������С�������� 
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> c(n);
    c[0] = 1; 
    for(int i = 1; i < n; i++){
    	int a;
    	cin >> a;
    	c[i] = c[i-1]*a;
	}
	ll pre = 0;
	for(int i = 1; i < n; i++){
		int b = (m%c[i] - pre) / c[i-1];
		cout << b << " ";
		pre = m%c[i];
	}
	int b = (m - pre) / c[n-1];
	cout << b;
	return 0;
}

