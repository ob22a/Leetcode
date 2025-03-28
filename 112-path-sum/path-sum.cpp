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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;

        vector<tuple<TreeNode*,int>> stack={{root,root->val}};
        
        while(!stack.empty()){
            auto [node,sum]=stack.back();
            stack.pop_back();
            if(node->left==nullptr && node->right==nullptr){
                if(sum==targetSum) return true;
            }
            if(node->left!=nullptr) stack.push_back({node->left,sum+node->left->val});

            if(node->right!=nullptr) stack.push_back({node->right,sum+node->right->val});
        }
        return false;
    }
};