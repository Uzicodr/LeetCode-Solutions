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
    TreeNode* func(vector<int>&nums,int low,int high){
        if(low>high)
        return NULL;

        int mid=(high+low)/2;
        TreeNode* newnode=new TreeNode(nums[mid]);
        newnode->left=func(nums,low,mid-1);
        newnode->right=func(nums,mid+1,high);

        return newnode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=func(nums,0,nums.size()-1);
        return root;
    }
};