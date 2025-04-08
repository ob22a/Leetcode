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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        stack<tuple<TreeNode*,string>> nodeStack;
        nodeStack.push({root,to_string(root->val)});

        while(!nodeStack.empty()){
            auto [node,stringPath] = nodeStack.top();
            nodeStack.pop();
            if(node->left) nodeStack.push({node->left,stringPath+"->"+to_string(node->left->val)});
            if(node->right) nodeStack.push({node->right,stringPath+"->"+to_string(node->right->val)});
            if(!node->left && !node->right) paths.push_back(stringPath);
        }
        return paths;
    }
};