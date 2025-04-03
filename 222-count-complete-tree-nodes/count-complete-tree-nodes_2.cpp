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
    int countNodes(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        int count=0;

        if(root) nodeStack.push(root);
       
        while(!nodeStack.empty()){
            TreeNode* last = nodeStack.top();
            nodeStack.pop();
            ++count;
            if(last->left) nodeStack.push(last->left);
            if(last->right) nodeStack.push(last->right);
        }
        return count;
    }
};
