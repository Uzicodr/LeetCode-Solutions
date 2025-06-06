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
    void func(TreeNode* root,bool flag,int& ans){
        if(root==NULL){
            return;
        }

        if(root->left==NULL && root->right==NULL){
            if(flag==true){
                ans+=root->val;
            }
        }

        func(root->left,true,ans);
        func(root->right,false,ans);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        func(root,false,ans);
        return ans;
    }
};