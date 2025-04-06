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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* current=root;
        stack<TreeNode*> s;
        if(current) s.push(current);

        while(!s.empty()){
            TreeNode* node=s.top();
            s.pop();
            
            if(!node->left && !node->right) continue;
            TreeNode* temp=node->left;
            node->left=node->right;
            node->right=temp;

            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);
        }
        return root;
    }
};