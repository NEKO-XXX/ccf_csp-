#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 5;
#define eps 1e-8
double a[N][N];
int n, m, t, k, q;

int gauss(int n, int m) { // ��˹��Ԫ 
    int rnk = 0;
    for (int i = 1; i <= n; i++) { // �ӵ�һ�п�ʼ�������д��� 
        int t = rnk + 1; // ��һ��δ������ 
        for (int j = rnk + 1; j <= n; j++) // ����δ������
            if (fabs(a[j][i]) > eps) { t = j; break; } // ���е�i��Ԫ��������0 
        if (fabs(a[t][i]) < eps) continue;  // ��ǰ��ȫΪ0������
        ++rnk; // �ȼ�1 
        for (int j = i; j <= m; j++) swap(a[t][j], a[rnk][j]); // ����Ԫ�н�������rnk��
        for (int j = m; j >= i; j--) a[rnk][j] /= a[rnk][i]; // ��Ԫa[rnk][i]��Ϊ1 
        for (int j = rnk + 1; j <= n; j++) // ������Ԫ�·���ÿһ�У�j ���кţ� 
            if (fabs(a[j][i]) > eps)  // ����ǰԪ�ط��㣨����Ԫ��
                for (int k = m; k >= i; k--) // ����������ǰ�е�ÿһ�У�k ���кţ�
                    a[j][k] -= a[rnk][k] * a[j][i];  // ��ȥ��Ԫ�еı�����Ϊ��a[j][i] = 0 
    }
    return rnk;
}

void work() {
    cin >> n;
    vector<string> s(n);
    for (auto& ss : s) cin >> ss; 
    map<string, int> mp;
    int cnt = 0;
    memset(a, 0, sizeof(a)); // ��ʼ��a����ȫΪ0 
    
    for (int i = 0; i < n; i++) {
        auto& ss = s[i];
        for (int l = 0, r = 0; l < ss.length(); r = l = r + 1) {
            auto isNum = [&] (char c) -> bool { return c >= '0' && c <= '9'; };
            while (r + 1 < ss.length() && !(isNum(ss[r]) && !isNum(ss[r + 1]))) r++; // ��ǰ�ַ������֣�����һ���ַ��Ƿ����֣������ֲ��ֽ�����
            string cur = ss.substr(l, r - l + 1), elem;
            for (auto ch : cur) if (!isNum(ch)) elem += ch;
            int num = stoi(cur.substr(elem.length()));            
            int elemid = mp.count(elem) ? mp[elem] : (mp[elem] = ++cnt); // cnt ��Ԫ�ؼ���������¼�ѷ��ֵ�Ԫ������
            a[elemid][i + 1] = num; // �� elemid ��Ԫ���ڵ� i+1 �������е�����Ϊ num
        }
    }
    int rnk = gauss(cnt, n);
    cout << "NY"[rnk < n] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Case = 1;
    cin >> Case;
    while (Case--) work();
    return 0;
}

