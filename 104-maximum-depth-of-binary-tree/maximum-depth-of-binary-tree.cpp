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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        vector<tuple<TreeNode*,int>> nodeHeight={{root,1}};
        int height=1;
        while(!nodeHeight.empty()){
            tuple<TreeNode*,int> node=nodeHeight.back();
            nodeHeight.pop_back();
            if(get<1>(node)>height) height=get<1>(node);
            if(get<0>(node)->left!=nullptr) nodeHeight.push_back({get<0>(node)->left,get<1>(node)+1});
            if(get<0>(node)->right!=nullptr) nodeHeight.push_back({get<0>(node)->right,get<1>(node)+1});
        }
        return height;
    }
};