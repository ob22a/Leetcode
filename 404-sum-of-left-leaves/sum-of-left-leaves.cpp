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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        int leftSum=0;
        nodeStack.push(root);

        while(!nodeStack.empty()){
            TreeNode* node = nodeStack.top();
            nodeStack.pop();

            if(node->left && !node->left->left && !node->left->right) leftSum+=node->left->val;

            if(node->right) nodeStack.push(node->right);
            if(node->left) nodeStack.push(node->left);
        }
        
        return leftSum;
    }
};