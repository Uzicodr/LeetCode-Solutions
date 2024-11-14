/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL){
            return 0;
        }

        vector<int> sizes(root->children.size());
        
        if (sizes.empty()) {
            return 1;
        }
        for(int i=0;i<root->children.size();i++){
            sizes[i]=maxDepth(root->children[i]);
        }

        sort(sizes.begin(),sizes.end());
        return 1+sizes[sizes.size()-1];
    }
};