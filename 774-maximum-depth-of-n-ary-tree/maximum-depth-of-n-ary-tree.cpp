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
                                                                   //no extra space
    int maxDepth(Node* root) {
        if(root==NULL){
            return 0;
        }

        //vector<int> sizes(root->children.size());

        int maxh=0;
        for(int i=0;i<root->children.size();i++){
            maxh=max(maxh,maxDepth(root->children[i]));
        }

        //sort(sizes.begin(),sizes.end());
        return 1+maxh;
    }
};