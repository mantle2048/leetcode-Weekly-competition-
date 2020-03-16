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
    int ans = 0;

    //dp[x][left/right] 当前节点x向左走和向右走的结点数
    //f->left -> dp[x][right] 如果f向左走到达x则 dp[f][0] = dp[x][1] + 1
    //f->right -> dp[x][left] dp[f][1] = dp[x][0] + 1
    pair<int, int> dfs(TreeNode* rt){
        if(rt == NULL) return make_pair(0,0);
        int l = 1, r = 1; // l 和 r 记录访问过的节点数
        l = 1 + dfs(rt->left).second;
        r = 1 + dfs(rt->right).first;
        ans = max(ans, max(l,r));
        return make_pair(l,r);
    }
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans - 1;
    }
};