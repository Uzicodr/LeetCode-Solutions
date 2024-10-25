/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool func(TreeNode* root,long long lower, long long upper){
        if(root==NULL)
        return true;

        if(root->val>=upper || root->val<=lower){
            return false;
        }

        if(func(root->left,lower,root->val) && func(root->right,root->val,upper)){
            return true;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return func(root,LLONG_MIN, LLONG_MAX);
    }
};