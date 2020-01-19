#include<iostream>
#include<vector>
using namespace std;
//name:删除给定值的叶子节点
//前序遍历，递归深入的过程中不要删除，要等到递归弹出的是时候再删除
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
        //如果在这里直接对rt->left || right 操作就是在递归上升时操作
        rt->left = BFS(rt->left, target); //这种获取返回值后再操作就是递归返回时操作，
        rt->right = BFS(rt->right, target);
        if(rt->left == NULL && rt->right == NULL && rt->val == target) rt = NULL;
        return rt;
    }
};