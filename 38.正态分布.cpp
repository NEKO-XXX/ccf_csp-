// ��������ȷ���� 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin >> k;
	while(k--){
		double u,q,n;
		double z;
		cin >> u >> q >> n;
		z = (n-u) / q;
		stringstream ss;
		ss << fixed << setprecision(0) << z*100; // �� z*100 �Ľ���� ������ 0 λС���Ĺ̶���ʽ�� д���ַ����� ss ��
		string numstr = ss.str();
		int num = stoi(numstr);
		int i = num / 10 + 1;
		int j = num % 10 + 1;
		cout << i << " " << j << endl; 
	}
	return 0;
} 
