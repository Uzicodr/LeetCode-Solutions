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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int level=1;
        int ans=level;
        int maxsum=INT_MIN;
        q.push(root);
        while(!q.empty()){
            int sum=0;
            int levelsize=q.size();

            for(int i=0;i<levelsize;i++){
                TreeNode* frontnode=q.front();
                q.pop();

                sum+=frontnode->val;
                if(frontnode->left){
                    q.push(frontnode->left);
                }
                if(frontnode->right){
                    q.push(frontnode->right);
                }
            }
            if(sum>maxsum){
                maxsum=sum;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};