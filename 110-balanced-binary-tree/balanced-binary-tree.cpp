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
    bool balanced=true;
    int helper(TreeNode* root){
        if(root==nullptr) return 0;
        int leftHeight=this->helper(root->left);
        int rightHeight=this->helper(root->right);
        if(abs(leftHeight-rightHeight)>1){
            this->balanced=false;
            return 0;
        }
        return max(leftHeight,rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        helper(root);
        return this->balanced;
    }
};