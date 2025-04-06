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
        stack<TreeNode*> nodeStack;
        if(root) nodeStack.push(root);

        while(!nodeStack.empty()){
            TreeNode* node=nodeStack.top();
            nodeStack.pop();
            
            if(!node->left && !node->right) continue;
            TreeNode* temp=node->left;
            node->left=node->right;
            node->right=temp;

            if(node->left) nodeStack.push(node->left);
            if(node->right) nodeStack.push(node->right);
        }
        return root;
    }
};