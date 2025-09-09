#include<bits/stdc++.h>
using namespace std;
double a[1002];
int n;

int main(){
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	int sum1 = 0;
	long long sum2 = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum1 += a[i];
		sum2 += a[i]*a[i];
	}
	double aver = double(sum1) / n;
	double fenmu = sqrt(double(sum2) / n - pow(aver, 2));
	for(int i = 0; i < n; i++){
		a[i] = (a[i]-aver) / fenmu;
	}
	for(int i = 0; i < n; i++){
		cout << fixed << setprecision(6) << a[i] << endl;
	}
	return 0;
}
