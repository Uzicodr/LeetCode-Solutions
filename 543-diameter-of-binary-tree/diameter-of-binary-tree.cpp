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
    int func(TreeNode* root,int &maxh){
        if(root==NULL){
            return 0;
        }

        int lh=func(root->left,maxh);        //recursive height method
        int rh=func(root->right,maxh);      //recursive height method

        maxh=max(maxh,lh+rh);     //update maxh(passed as reference)
        return max(lh,rh)+1;     //return max height
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxh=0;      //pass it as reference
        func(root,maxh);
        return maxh;
    }
};