// 思路：二叉搜索树中序遍历为有序数组
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> buf;
    void dfs(TreeNode* rt){
        if(rt == NULL) return;
        dfs(rt->left);
        buf.push_back(rt->val);
        dfs(rt->right);
        return;
    }
    // TreeNode* create_Tree(int low, int high){ //[low, high]
    //     if(low > high) return NULL;
    //     int mid = (low + high) >> 1;
    //     TreeNode* ret = new TreeNode(buf[mid]);
    //     ret->left = create_Tree(low, mid - 1);
    //     ret->right = create_Tree(mid + 1, high);
    //     return ret;
    // }
    TreeNode* create_Tree(int low, int high){// [low, high)
        if(low >= high) return NULL;
        int mid = (low + high) >> 1;
        TreeNode* ret = new TreeNode(buf[mid]);
        ret->left = create_Tree(low, mid);
        ret->right = create_Tree(mid + 1, high);
        return ret;
    }
    TreeNode* balanceBST(TreeNode* root) {
        buf.clear();
        dfs(root);
        int n = buf.size();
        if(n == 0) return NULL;
        return create_Tree(0, n);
    }
};