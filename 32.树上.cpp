#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2005;
int n, m;
struct Node {
    int w;
    vector<int> children;    // ֱ���ӽڵ�
    ll total_descendant_w;   // �ýڵ㼰�����к������Ȩ��
    unordered_set<int> descendants; // �ýڵ�����к���������Լ���
} ns[N];

// Ԥ����ÿ���ڵ�ĺ����Ȩ�غͺ������
void dfs(int u) {
    ns[u].descendants.insert(u);
    ns[u].total_descendant_w = ns[u].w;
    for (int v : ns[u].children) {
        dfs(v);
        // �ϲ�������Ϻ���Ȩ��
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
        if (excluded.count(i)) continue; // ���ų��Ľڵ�����
        // ����ýڵ㼰��������Ȩ�أ�δ���ų��Ĳ��֣�
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
    dfs(1); // Ԥ�������нڵ�ĺ����Ϣ

    while (m--) {
        int target;
        cin >> target;
        unordered_set<int> excluded;
        ll current_sum = total_sum;
        vector<int> query_seq;

        while (excluded
		.size() < n - 1) { // ֱ��ֻʣһ���ڵ�
            int idx = cal(current_sum, excluded);
            query_seq.push_back(idx);
            if (idx == target) {
                // ����Ŀ��ڵ㼰�������ų������ڵ�
                for (int i = 1; i <= n; ++i) {
                    if (i != idx && !ns[idx].descendants.count(i)) {
                        excluded.insert(i);
                        current_sum -= ns[i].w;
                    }
                }
            } else {
                // �ų���ǰ�ڵ㼰����
                for (int d : ns[idx].descendants) {
                    if (!excluded.count(d)) {
                        excluded.insert(d);
                        current_sum -= ns[d].w;
                    }
                }
            }
            //if (excluded.size() == n - 1) break; // ֻʣһ���ڵ�
        }

        for (int x : query_seq) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
