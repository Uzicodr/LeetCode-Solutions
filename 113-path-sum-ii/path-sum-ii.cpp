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
    void func(TreeNode* root, int targetSum,vector<vector<int>>& ans,vector<int>& possible){
        if(root==NULL){
            return;
        }

        targetSum-=root->val;
        if(root->left==NULL && root->right==NULL){
            if(targetSum==0){
                ans.push_back(possible);
            }
        }

        if(root->left!=NULL){
            possible.push_back(root->left->val);
            func(root->left,targetSum,ans,possible);
            possible.pop_back();
        }


        if(root->right!=NULL){
            possible.push_back(root->right->val);
            func(root->right,targetSum,ans,possible);
            possible.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> ans;
        vector<int> possible;
        possible.push_back(root->val);
        func(root,targetSum,ans,possible);
        return ans;
    }
};