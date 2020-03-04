// name:�������е��б�
// ˼·��������Ҳ�������ֱ�ӱ���(��������ó���DFS)������DFS����ÿ��Tree��NodeȻ��ӵ�ǰ�Ľڵ�root����������check��������Ƿ���һ��·����ƥ����������
// tips:DFSģ��
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