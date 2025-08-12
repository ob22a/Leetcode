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
    int diameterOfBinaryTree(TreeNode* root) {
        // Height of left + height of right for each node
        int dia=0;
        auto height = [&](auto&& self,TreeNode* node){
            if(!node) return 0;
            int leftHeight=self(self,node->left);
            int rightHeight=self(self,node->right);

            dia=max(dia,leftHeight+rightHeight);
            return max(leftHeight,rightHeight)+1;
        };

        height(height,root);

        return dia;
    }
};