#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2005;
int n, m;
struct Node {
    int w;
    vector<int> children;    // 直接子节点
    ll total_descendant_w;   // 该节点及其所有后代的总权重
    unordered_set<int> descendants; // 该节点的所有后代（包含自己）
} ns[N];

// 预处理每个节点的后代总权重和后代集合
void dfs(int u) {
    ns[u].descendants.insert(u);
    ns[u].total_descendant_w = ns[u].w;
    for (int v : ns[u].children) {
        dfs(v);
        // 合并后代集合和总权重
        for (int d : ns[v].descendants) {
            ns[u].descendants.insert(d);
        }
        ns[u].total_descendant_w += ns[v].total_descendant_w;
    }
}
int cal(ll sum, const unordered_set<int>& excluded) {
    ll min_diff = LLONG_MAX;
    int best_idx = 1;
    for (int i = 1; i <= n; ++i) {
        if (excluded.count(i)) continue; // 已排除的节点跳过
        // 计算该节点及其后代的总权重（未被排除的部分）
        ll current_w = 0;
        for (int d : ns[i].descendants) {
            if (!excluded.count(d)) {
                current_w += ns[d].w;
            }
        }
        ll diff = abs(2 * current_w - sum);
        if (diff < min_diff || (diff == min_diff && i < best_idx)) {
            min_diff = diff;
            best_idx = i;
        }
    }
    return best_idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    ll total_sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> ns[i].w;
        total_sum += ns[i].w;
    }
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        ns[p].children.push_back(i);
    }
    dfs(1); // 预处理所有节点的后代信息

    while (m--) {
        int target;
        cin >> target;
        unordered_set<int> excluded;
        ll current_sum = total_sum;
        vector<int> query_seq;

        while (excluded
		.size() < n - 1) { // 直到只剩一个节点
            int idx = cal(current_sum, excluded);
            query_seq.push_back(idx);
            if (idx == target) {
                // 保留目标节点及其后代，排除其他节点
                for (int i = 1; i <= n; ++i) {
                    if (i != idx && !ns[idx].descendants.count(i)) {
                        excluded.insert(i);
                        current_sum -= ns[i].w;
                    }
                }
            } else {
                // 排除当前节点及其后代
                for (int d : ns[idx].descendants) {
                    if (!excluded.count(d)) {
                        excluded.insert(d);
                        current_sum -= ns[d].w;
                    }
                }
            }
            //if (excluded.size() == n - 1) break; // 只剩一个节点
        }

        for (int x : query_seq) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
