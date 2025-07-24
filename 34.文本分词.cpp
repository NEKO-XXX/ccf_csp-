/*
    Created by Pujx on 2024/7/18.
*/
#pragma GCC optimize(2, 3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
//#define double long double
using i64 = long long;
using ui64 = unsigned long long;
//using i128 = __int128;
#define inf (int)0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define yn(x) cout << (x ? "yes" : "no") << endl
#define Yn(x) cout << (x ? "Yes" : "No") << endl
#define YN(x) cout << (x ? "YES" : "NO") << endl
#define mem(x, i) memset(x, i, sizeof(x))
#define cinarr(a, n) for (int _ = 1; _ <= n; _++) cin >> a[_]
#define cinstl(a) for (auto& _ : a) cin >> _
#define coutarr(a, n) for (int _ = 1; _ <= n; _++) cout << a[_] << " \n"[_ == n]
#define coutstl(a) for (const auto& _ : a) cout << _ << ' '; cout << endl
#define all(x) (x).begin(), (x).end()
#define ls (s << 1)
#define rs (s << 1 | 1)
#define ft first
#define se second
#define pii pair<int, int>
#ifdef DEBUG
    #include "debug.h"
#else
    #define dbg(...) void(0)
#endif

const int N = 2e5 + 5;
//const int M = 1e5 + 5;
const int mod = 998244353;
//const int mod = 1e9 + 7;
//template <typename T> T ksm(T a, i64 b) { T ans = 1; for (; b; a = 1ll * a * a, b >>= 1) if (b & 1) ans = 1ll * ans * a; return ans; }
//template <typename T> T ksm(T a, i64 b, T m = mod) { T ans = 1; for (; b; a = 1ll * a * a % m, b >>= 1) if (b & 1) ans = 1ll * ans * a % m; return ans; }

int a[N];
int n, m, t, k, q;

vector<vector<int>> v;      // 每个字符串转换为字符索引后的表示
vector<int> cnt;            // 每个字符串的权重
vector<string> ans;         // 存储最终生成的字符串

// 表示一个字符串对的信息，用于优先队列
struct node {
    int id1, id2, cnt, vis; // id1和id2是字符串索引，cnt是权重，vis是版本号
    bool operator < (const node& t) const {
        // 优先合并权重大的对
        if (cnt != t.cnt) return cnt < t.cnt;
        // 权重相同的情况下，优先合并长度较短的
        if (ans[id1].length() + ans[id2].length() != ans[t.id1].length() + ans[t.id2].length())
            return ans[id1].length() + ans[id2].length() > ans[t.id1].length() + ans[t.id2].length();
        // 长度相同的情况下，优先合并第一个字符串较短的
        if (ans[id1].length() != ans[t.id1].length())
            return ans[id1].length() > ans[t.id1].length();
        // 否则按字典序比较
        return ans[id1] + ans[id2] > ans[t.id1] + ans[t.id2];
    }
};
priority_queue<node> pq;    // 优先队列，用于贪心选择最优合并对

// 记录字符串对的信息
struct Info {
    multiset<int> posi;     // 包含该字符串对的所有字符串索引
    int cnt, vis;           // 总权重和版本号
};
map<pair<int, int>, Info> mpInfo; // 记录所有字符串对的信息
Info& getInfo(int id1, int id2) {  // 获取或创建字符串对的信息
    if (mpInfo.count({id1, id2})) return mpInfo[{id1, id2}];
    else return mpInfo[{id1, id2}] = {multiset<int>(), 0, 0};
}

// 主处理函数
void work() {
    cin >> n >> m;
    vector<string> s(n);    // 存储初始输入的字符串
    vector<int> vis(26, 0); // 标记出现过的字符
    v.resize(n), cnt.resize(n);
    
    // 读取输入数据并标记出现过的字符
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> cnt[i];
        for (auto& ch : s[i]) vis[ch - 'a'] = 1;
    }
    
    // 初始化结果数组，每个出现过的字符作为一个单独的字符串
    for (int i = 0; i < 26; i++) {
        if (vis[i])
            ans.emplace_back(string(1, 'a' + i));
        if (i) vis[i] += vis[i - 1];
    }

    // 将每个字符串转换为字符索引序列，并记录相邻字符对的信息
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].length(); j++) {
            // 将字符映射为连续的索引
            v[i].emplace_back(vis[s[i][j] - 'a'] - 1);
            if (j) {
                // 记录相邻字符对的信息
                Info& info = getInfo(v[i][j - 1], v[i][j]);
                info.posi.emplace(i), info.cnt += cnt[i], ++info.vis;
                pq.emplace((node){v[i][j - 1], v[i][j], info.cnt, info.vis});
            }
        }
    }

    // 贪心合并过程，直到生成M个字符串或无法继续合并
    while (ans.size() < m) {
        // 弹出队列中过时的元素
        while (pq.size() && pq.top().vis != mpInfo[{pq.top().id1, pq.top().id2}].vis) pq.pop();
        if (pq.empty()) break;
        if (pq.top().cnt == 0) break;

        int id1 = pq.top().id1, id2 = pq.top().id2;
        dbg(id1, id2);
        Info& info = getInfo(id1, id2);
        pq.pop();
        
        // 合并两个字符串并加入结果集
        ans.emplace_back(ans[id1] + ans[id2]);

        // 更新所有包含该字符串对的字符串
        for (auto i : info.posi) {
            int p = -1;
            // 查找字符串对在当前字符串中的位置
            for (int j = 0; j < v[i].size() - 1; j++)
                if (v[i][j] == id1 && v[i][j + 1] == id2) {
                    p = j;
                    break;
                }
            if (p == -1) continue;

            // 辅助函数：移除一个字符串对的信息
            auto remove = [&] (int id1, int id2, int idx) {
                Info& tem = getInfo(id1, id2);
                if (&tem.posi == &info.posi) return;
                tem.posi.erase(tem.posi.find(idx));
                tem.cnt -= cnt[idx], ++tem.vis;
                pq.emplace((node){id1, id2, tem.cnt, tem.vis});
            };
            // 辅助函数：添加一个字符串对的信息
            auto add = [&] (int id1, int id2, int idx) {
                Info& tem = getInfo(id1, id2);
                if (&tem.posi == &info.posi) return;
                tem.posi.emplace(idx);
                tem.cnt += cnt[idx], ++tem.vis;
                pq.emplace((node){id1, id2, tem.cnt, tem.vis});
            };

            // 移除合并前的相邻对信息
            if (p) remove(v[i][p - 1], v[i][p], i);
            if (p + 2 < v[i].size()) remove(v[i][p + 1], v[i][p + 2], i);

            // 执行合并操作：移除第二个字符串索引，将第一个替换为合并后的新索引
            v[i].erase(v[i].begin() + p + 1);
            v[i][p] = ans.size() - 1;

            // 添加合并后的新相邻对信息
            if (p) add(v[i][p - 1], v[i][p], i);
            if (p + 1 < v[i].size()) add(v[i][p], v[i][p + 1], i);
        }

        // 清空原字符串对的信息
        info.posi.clear();
        info.cnt = 0, ++info.vis;
        pq.emplace((node){id1, id2, info.cnt, info.vis});
    }

    // 输出最终生成的所有字符串
    for (auto& str : ans) cout << str << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\admin\\CLionProjects\\Practice\\data.in", "r", stdin);
    freopen("C:\\Users\\admin\\CLionProjects\\Practice\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Case = 1;
    //cin >> Case;
    while (Case--) work();
    return 0;
}
