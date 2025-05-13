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
        if(!root) return 0;
        
        stack<tuple<Node*,int>> s;
        int maxHeight=0;
        s.push({root,1});

        while(!s.empty()){
            auto[node,height]=s.top();
            s.pop();

            maxHeight=max(maxHeight,height);

            for(int i=0;i<node->children.size();++i){
                s.push({node->children[i],height+1});
            }
        }
        return maxHeight;
    }
};