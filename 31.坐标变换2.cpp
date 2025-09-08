#include<bits/stdc++.h>
using namespace std;

double k[1005];      // 缩放系数
double t[1005];      // 旋转角度
double prek[1005];   // 前缀乘积（累积缩放）
double pret[1005];   // 前缀和（累积旋转）

int main(){
    int n, m;
    cin >> n >> m;
    
    // 初始化第一个元素（变换前的初始状态）
    k[0] = 1;         // 初始缩放系数为1
    t[0] = 0;         // 初始旋转角度为0
    prek[0] = 1;      // 初始累积缩放为1
    pret[0] = 0;      // 初始累积旋转为0
    
    for(int i = 1; i <= n; i++){
        // 初始化当前变换
        k[i] = 1;     // 默认为不缩放
        t[i] = 0;     // 默认为不旋转
        
        int a;
        double b;
        cin >> a >> b;
        
        if(a == 1){
            // 缩放变换
            k[i] = b;
        }else{
            // 旋转变换（注意：通常角度需要转换为弧度）
            t[i] = b;
        }
    }
    
    // 计算前缀数组（累积变换）
    for(int i = 1; i <= n; i++){
        prek[i] = prek[i-1] * k[i];  // 累积缩放（乘法）
        pret[i] = pret[i-1] + t[i];  // 累积旋转（加法）
    }
    
    // 处理查询
    for(int f = 0; f < m; f++){
        int i, j; 
        double x, y;
        cin >> i >> j;
        scanf("%lf %lf", &x, &y);
        
        // 计算从i到j的总变换
        double K = prek[j] / prek[i-1];  // 总缩放系数
        double T = pret[j] - pret[i-1];  // 总旋转角度
        
        // 先旋转（使用原始x值计算y）
        double original_x = x;
        x = original_x * cos(T) - y * sin(T);
        y = original_x * sin(T) + y * cos(T);
        
        // 再缩放
        x *= K;
        y *= K;
        
        cout << fixed << setprecision(6) << x << " " << y << endl;
    }
    
    return 0;
}

