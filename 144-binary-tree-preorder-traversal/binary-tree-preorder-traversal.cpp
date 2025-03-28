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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};

        vector<int>sol;
        vector<TreeNode*> stack={root};

        while(!stack.empty()){
            TreeNode* node=stack.back();
            stack.pop_back();
            sol.push_back(node->val);
            if(node->right!=nullptr) stack.push_back(node->right);
            if(node->left!=nullptr) stack.push_back(node->left);
        }
        return sol;
    }
};