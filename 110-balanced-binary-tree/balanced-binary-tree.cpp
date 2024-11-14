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
    int getheight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(getheight(root->left),getheight(root->right))+1;
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        int leftchild=getheight(root->left);
        int rightchild=getheight(root->right);

        int balancefactor=leftchild-rightchild;
        if(balancefactor>1 || balancefactor<-1){
            return false;
        }

        bool checkleft=isBalanced(root->left);
        bool checkright=isBalanced(root->right);

        if(checkleft==false || checkright==false){
            return false;
        }
        return right;
    }
};