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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
        return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;

        while(!q.empty()){
            int sizeoflevel=q.size();
            vector<int> storelevel(sizeoflevel);

            for(int i=0;i<sizeoflevel;i++){
                TreeNode* frontnode=q.front();
                q.pop();

                int idx;
                if(flag==0){
                    idx=i;
                }
                else{
                    idx=sizeoflevel-i-1;
                }

                storelevel[idx]=frontnode->val;

                if(frontnode->left){
                    q.push(frontnode->left);
                }
                if(frontnode->right){
                    q.push(frontnode->right);
                }
            }
            ans.push_back(storelevel);
            flag=!flag;
        }
        return ans;
    }
};