/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int ans = 1;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelsize = q.size();

            for (int i = 0; i < levelsize; i++) {
                TreeNode* frontnode = q.front();
                q.pop();
                if (frontnode->left == NULL && frontnode->right == NULL) {
                    return ans;
                }

                if (frontnode->left) {
                    q.push(frontnode->left);
                }
                if (frontnode->right) {
                    q.push(frontnode->right);
                }
            }
            ans++;
        }
        return ans;
    }
};