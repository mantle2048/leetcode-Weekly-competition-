// name: 分裂二叉树的最大乘积
// 先用前序遍历求出树的节点总和sum， 再前序遍历，在递归返回时求出每个子树的和ret，然后用 ret * (sum - ret)求最大值
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