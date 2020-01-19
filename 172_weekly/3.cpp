#include<iostream>
#include<vector>
using namespace std;
//name:ɾ������ֵ��Ҷ�ӽڵ�
//ǰ��������ݹ�����Ĺ����в�Ҫɾ����Ҫ�ȵ��ݹ鵯������ʱ����ɾ��
//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return BFS(root, target);
    }
    TreeNode* BFS(TreeNode* rt, int target){
        if(rt == NULL) return rt;
        //���������ֱ�Ӷ�rt->left || right ���������ڵݹ�����ʱ����
        rt->left = BFS(rt->left, target); //���ֻ�ȡ����ֵ���ٲ������ǵݹ鷵��ʱ������
        rt->right = BFS(rt->right, target);
        if(rt->left == NULL && rt->right == NULL && rt->val == target) rt = NULL;
        return rt;
    }
};