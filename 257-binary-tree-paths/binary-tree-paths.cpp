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
    void func(vector<string>& paths,string possible,TreeNode* root){
        if(root==NULL){
            return;
        }

        if(!possible.empty()){
            possible+="->";
        }

        possible+=to_string(root->val);

        if(root->left==NULL && root->right==NULL){
            paths.push_back(possible);
            return;
        }

        func(paths,possible,root->left);
        func(paths,possible,root->right);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL){
            return {};
        }

        vector<string> paths;
        func(paths,"",root);

        return paths;
    }
};