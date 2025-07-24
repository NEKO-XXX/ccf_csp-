#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	set<string> s1, s2, s3;
	while(n--){
		string s;
		cin >> s;
		for(auto& c : s){
			c = tolower(c);
		}
		s1.insert(s);
		s3.insert(s);
	} 
	while(m--){
		string s;
		cin >> s;
		for(auto& c : s){
			c = tolower(c);
		}
		s2.insert(s);
		s3.insert(s);
	} 
	int a = s1.size() + s2.size() - s3.size();
	int b = s3.size();
	cout << a << endl;
	cout << b << endl;
	return 0;
}
