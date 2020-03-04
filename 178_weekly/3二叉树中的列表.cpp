// name:二叉树中的列表
// 思路：数据量也不大可以直接暴力(又是我最不擅长的DFS)，先用DFS遍历每个Tree的Node然后从当前的节点root出发，调用check函数检查是否有一条路可以匹配整个链表
// tips:DFS模板
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool check(ListNode* head, TreeNode* root){
        if(head == NULL) return true;
        if(root == NULL) return false;
        if(root->val != head->val) return false;
        bool ret = false;
        ret = ret || check(head->next, root->left);
        ret = ret || check(head->next, root->right);
        return ret;
    }
    bool dfs(ListNode* head, TreeNode* root){
        if(root == NULL)
            return false;
        bool ret = false;
        ret = ret || check(head, root);
        ret = ret || dfs(head, root->left);
        ret = ret || dfs(head, root->right);
        return ret;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, root);
    }
};