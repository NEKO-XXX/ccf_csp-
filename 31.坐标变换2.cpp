#include<bits/stdc++.h>
using namespace std;

double k[1005];      // ����ϵ��
double t[1005];      // ��ת�Ƕ�
double prek[1005];   // ǰ׺�˻����ۻ����ţ�
double pret[1005];   // ǰ׺�ͣ��ۻ���ת��

int main(){
    int n, m;
    cin >> n >> m;
    
    // ��ʼ����һ��Ԫ�أ��任ǰ�ĳ�ʼ״̬��
    k[0] = 1;         // ��ʼ����ϵ��Ϊ1
    t[0] = 0;         // ��ʼ��ת�Ƕ�Ϊ0
    prek[0] = 1;      // ��ʼ�ۻ�����Ϊ1
    pret[0] = 0;      // ��ʼ�ۻ���תΪ0
    
    for(int i = 1; i <= n; i++){
        // ��ʼ����ǰ�任
        k[i] = 1;     // Ĭ��Ϊ������
        t[i] = 0;     // Ĭ��Ϊ����ת
        
        int a;
        double b;
        cin >> a >> b;
        
        if(a == 1){
            // ���ű任
            k[i] = b;
        }else{
            // ��ת�任��ע�⣺ͨ���Ƕ���Ҫת��Ϊ���ȣ�
            t[i] = b;
        }
    }
    
    // ����ǰ׺���飨�ۻ��任��
    for(int i = 1; i <= n; i++){
        prek[i] = prek[i-1] * k[i];  // �ۻ����ţ��˷���
        pret[i] = pret[i-1] + t[i];  // �ۻ���ת���ӷ���
    }
    
    // �����ѯ
    for(int f = 0; f < m; f++){
        int i, j; 
        double x, y;
        cin >> i >> j;
        scanf("%lf %lf", &x, &y);
        
        // �����i��j���ܱ任
        double K = prek[j] / prek[i-1];  // ������ϵ��
        double T = pret[j] - pret[i-1];  // ����ת�Ƕ�
        
        // ����ת��ʹ��ԭʼxֵ����y��
        double original_x = x;
        x = original_x * cos(T) - y * sin(T);
        y = original_x * sin(T) + y * cos(T);
        
        // ������
        x *= K;
        y *= K;
        
        cout << fixed << setprecision(6) << x << " " << y << endl;
    }
    
    return 0;
}

