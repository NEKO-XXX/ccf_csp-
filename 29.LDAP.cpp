// https://blog.suwako.cn/CSP-29th/
#include"bits/stdc++.h"
using namespace std;
struct user
{
    int DN;
    unordered_map<int, int> attribute;
};
array<user*, 2505>users;
int n;
vector<int>ans{};
string expr;
bool parse(int l, int r, user* me)
{
    if(expr[l] == '&' || expr[l] == '|') // �ж��Ƿ��Ǹ������
    {
        int count=1;
        for(int i=l+2; i<=r; ++i) // �������������ķֽ�
        {
            if(expr[i] == '(')
                ++count;
            else if(expr[i] == ')')
            {
                --count;
                if(count == 0)
                {
                    if(expr[l] == '&')
                        return parse(l+2, i-1, me) && parse(i+2, r-1, me);
                    else
                        return parse(l+2, i-1, me) || parse(i+2, r-1, me);
                }
            }
        }
    }
    // parse Base_Expr
    int a[2]={0, 0}, point=0;
    bool logic; // false='~', true=':'
    for(int i=l; i<=r; ++i) // �������˱ȽϷ����д�������ǲ�̫������⣬ֻ��˵ ^=1 ȷʵ�Ǹ��ö���
    {
        if(expr[i] == ':')
        {
            logic = true;
            point ^= 1;
            continue;
        }
        if(expr[i] == '~')
        {
            logic =false;
            point ^= 1;
            continue;
        }
        a[point] *= 10;
        a[point] += expr[i] - '0';
    }
    auto res = me->attribute.find(a[0]);
    if(res == me->attribute.end())
        return false;
    if(logic)
        return res->second == a[1];
    return res->second != a[1];
}
bool cmp(user *a, user *b)
{
    return a->DN < b->DN;
}
int main()
{
    scanf("%d", &n);
    int m, a, b;
    for(int i=1; i<=n; ++i)
    {
        users[i] = new user;
        scanf("%d%d", &users[i]->DN, &m);
        for(int j=1; j<=m; ++j)
        {
            scanf("%d%d", &a, &b);
            users[i]->attribute.emplace(a, b);
        }
    }
    sort(users.begin()+1, users.begin()+n+1, cmp); // �����������Ӻ���Ĵ𰸾�ֱ�Ӷ����������
    scanf("%d", &m);
    ++m; // ��Ϻ��� --m
    while(--m) // ����д�� m-- �ײ��ܶ౶��������������Ļ��Ͳ�����
    {
        cin>>expr;
        ans.clear();
        for(int i=1;i<=n;++i)
        {
            if(parse(0, expr.length()-1, users[i]))
                ans.emplace_back(users[i]->DN);
        }
        for(int &w:ans)
            printf("%d ", w);
        puts("");
    }
    return 0;
}
