// name: ���Ѷ����������˻�
// ����ǰ�����������Ľڵ��ܺ�sum�� ��ǰ��������ڵݹ鷵��ʱ���ÿ�������ĺ�ret��Ȼ���� ret * (sum - ret)�����ֵ
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define ll long long
const ll MOD = 1e9 + 7;
class Solution {
public:
    ll sum = 0, ans = 0;
    void dfs_sum(TreeNode* rt){
        if(rt == NULL) return;
        sum += rt->val;
        dfs_sum(rt->left);
        dfs_sum(rt->right);
    }
    int dfs_tree(TreeNode* rt){
        if(rt == NULL) return 0;
        int ret = rt->val;
        ret += dfs_tree(rt->left);
        ret += dfs_tree(rt->right);
        if(ans < ret * (sum - ret)) ans = ret * (sum - ret);
        return ret;
    }
    int maxProduct(TreeNode* root) {
        dfs_sum(root);
        dfs_tree(root);
        return ans % MOD;
    }
};