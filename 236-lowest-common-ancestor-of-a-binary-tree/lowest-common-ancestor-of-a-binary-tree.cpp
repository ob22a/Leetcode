/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto dfs = [&](auto&& self,TreeNode* node)->TreeNode*{
            if(!node || node==p || node==q) return node;
            TreeNode* node1 = self(self,node->left);
            TreeNode* node2 = self(self,node->right);
            if(node1 && node2) return node;
            return node1?node1:node2;
        };

        return dfs(dfs,root);
    }
};