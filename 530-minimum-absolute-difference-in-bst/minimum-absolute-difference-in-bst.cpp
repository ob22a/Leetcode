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
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        int ans = INT_MAX;

        auto inorder = [&](auto&& self,TreeNode* root)->void{
            if(root){
                self(self,root->left);
                if(prev!=-1) ans=min(ans,root->val-prev);
                prev = root->val;
                self(self,root->right);
            }
        };

        inorder(inorder,root);

        return ans;
    }
};