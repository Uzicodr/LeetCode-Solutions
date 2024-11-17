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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelsize=q.size();
            vector<int> storelevel(levelsize);

            for(int i=0;i<levelsize;i++){
                TreeNode* frontnode=q.front();
                q.pop();
                storelevel[i]=frontnode->val;
                if(frontnode->left){
                    q.push(frontnode->left);
                }
                if(frontnode->right){
                    q.push(frontnode->right);
                }
            }
            ans.push_back(storelevel);
        }
        return ans;
    }
};