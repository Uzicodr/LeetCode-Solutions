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
    TreeNode* findminimum(TreeNode* root){
        TreeNode* temp=root;

        while(temp!=NULL && temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }

        if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }

        if(key==root->val){
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }

            if(root->left==NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }

            if(root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }

            else{
                TreeNode* temp=findminimum(root->right);
                root->val=temp->val;
                root->right=deleteNode(root->right,temp->val);
            }
        }
        return root;
    }
};