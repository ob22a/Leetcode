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
    vector<string> paths;
    void helper(TreeNode* root,string nodePath){
        if(!root->left && !root->right){
            paths.push_back(nodePath);
            return ;
        }
        if(root->left)
            helper(root->left,nodePath+"->"+to_string(root->left->val));
        if(root->right) 
            helper(root->right,nodePath+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root,to_string(root->val));
        return paths;
    }
};