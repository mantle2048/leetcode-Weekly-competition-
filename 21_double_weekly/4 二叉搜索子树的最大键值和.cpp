/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// ˼·��DFS ÿ����������[low, high, is����������, sum]
// �ж�һ����rtΪ���������Ƿ��Ƕ��������������� 
// 1. l �� r ���Ƕ���������
// 2. l.high < rt->val < r.low
// rtΪ������������ֵ: low = min(rt->val, l.low(�п���ΪINF)) | high = max(rt->val, r.high)
 static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
const int INF = 4e4 + 50;
#define MP(a, b, c, d) make_pair(make_pair(a, b), make_pair(c, d))
#define PIIBI pair<pair<int, int>, pair<bool ,int>>
class Solution {
public:
    int ans = 0;
    pair<pair<int, int>, pair<bool ,int>> dfs(TreeNode* rt){
        if(rt == NULL) return MP(INF, -INF, true, 0);
        PIIBI l = dfs(rt->left);
        PIIBI r = dfs(rt->right);
        if((l.second.first && r.second.first) == false) return MP(0, 0, false, 0);
        if(l.first.second >= rt->val || rt->val >= r.first.first) return MP(0, 0, false, 0);
        int sum = rt->val + l.second.second + r.second.second;
        int mx = max(rt->val, r.first.second); // ��ֹ������ΪNULL��Ӧ��[INF, -INF, true, 0]
        int mi = min(rt->val, l.first.first);  // ��ֹ������ΪNULL��Ӧ��[INF, -INF, true, 0]
        ans = max(ans, sum);
        return MP(mi, mx, true, sum);
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};