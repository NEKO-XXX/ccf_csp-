#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 5;
#define eps 1e-8
double a[N][N];
int n, m, t, k, q;

int gauss(int n, int m) { // 高斯消元 
    int rnk = 0;
    for (int i = 1; i <= n; i++) { // 从第一列开始处理，按列处理 
        int t = rnk + 1; // 第一个未处理行 
        for (int j = rnk + 1; j <= n; j++) // 遍历未处理行
            if (fabs(a[j][i]) > eps) { t = j; break; } // 此行第i列元素若大于0 
        if (fabs(a[t][i]) < eps) continue;  // 当前列全为0，跳过
        ++rnk; // 秩加1 
        for (int j = i; j <= m; j++) swap(a[t][j], a[rnk][j]); // 将主元行交换到第rnk行
        for (int j = m; j >= i; j--) a[rnk][j] /= a[rnk][i]; // 主元a[rnk][i]化为1 
        for (int j = rnk + 1; j <= n; j++) // 处理主元下方的每一行（j 是行号） 
            if (fabs(a[j][i]) > eps)  // 若当前元素非零（需消元）
                for (int k = m; k >= i; k--) // 从右向左处理当前行的每一列（k 是列号）
                    a[j][k] -= a[rnk][k] * a[j][i];  // 减去主元行的倍数，为了a[j][i] = 0 
    }
    return rnk;
}

void work() {
    cin >> n;
    vector<string> s(n);
    for (auto& ss : s) cin >> ss; 
    map<string, int> mp;
    int cnt = 0;
    memset(a, 0, sizeof(a)); // 初始化a数组全为0 
    
    for (int i = 0; i < n; i++) {
        auto& ss = s[i];
        for (int l = 0, r = 0; l < ss.length(); r = l = r + 1) {
            auto isNum = [&] (char c) -> bool { return c >= '0' && c <= '9'; };
            while (r + 1 < ss.length() && !(isNum(ss[r]) && !isNum(ss[r + 1]))) r++; // 当前字符是数字，且下一个字符是非数字（即数字部分结束）
            string cur = ss.substr(l, r - l + 1), elem;
            for (auto ch : cur) if (!isNum(ch)) elem += ch;
            int num = stoi(cur.substr(elem.length()));            
            int elemid = mp.count(elem) ? mp[elem] : (mp[elem] = ++cnt); // cnt 是元素计数器，记录已发现的元素数量
            a[elemid][i + 1] = num; // 第 elemid 个元素在第 i+1 个物质中的数量为 num
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

